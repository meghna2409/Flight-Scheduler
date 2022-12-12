#include <string>
#include <vector>
#include <utility>

#include "../catch/catch.hpp"
#include "../flights.h"
#include "../dijkstra.h"
#include "../pagerank.h"

TEST_CASE("Route construction") {
    Route route("ORD", "DXB");
    REQUIRE(route.getDeparture() == "ORD");
    REQUIRE(route.getArrival() == "DXB");
}

TEST_CASE("Parsing airports.dat test 1") {
    Parse parse;
    parse.parseAirports("data/airports.dat.csv");
    std::pair<double, double> test;
    test = std::make_pair(41.9786, -87.9048);
    REQUIRE(parse.airport_coordinates["ORD"] == test);
}

TEST_CASE("Parsing airports.dat test 2") {
    Parse parse;
    parse.parseAirports("data/airports.dat.csv");
    std::pair<double, double> test;
    test = std::make_pair(25.2527999878, 55.3643989563);
    REQUIRE(parse.airport_coordinates["DXB"] == test);
}

TEST_CASE("Parsing airports.dat test 3") {
    Parse parse;
    parse.parseAirports("data/airports.dat.csv");
    std::pair<double, double> test;
    test = std::make_pair(8.48211956024, 76.9200973511);
    REQUIRE(parse.airport_coordinates["TRV"] == test);
}

TEST_CASE("Parsing routes.dat test 1") {
    Parse parse;
    parse.parseRoutes("data/airports.dat.csv", "data/routes.dat.csv");
    Route route("DEL", "COK");
    std::map<Route, double, Compare>::iterator it = parse.route_distances.find(route);
    double distance = parse.findRouteDistance(parse.airport_coordinates[route.getDeparture()].first, parse.airport_coordinates[route.getDeparture()].second,
    parse.airport_coordinates[route.getArrival()].first, parse.airport_coordinates[route.getArrival()].second);
    REQUIRE(parse.route_distances[route] == distance);
}

TEST_CASE("Parsing routes.dat test 2") {
    Parse parse;
    parse.parseRoutes("data/airports.dat.csv", "data/routes.dat.csv");
    Route route("DEN", "PIR");
    std::map<Route, double, Compare>::iterator it = parse.route_distances.find(route);
    double distance = parse.findRouteDistance(parse.airport_coordinates[route.getDeparture()].first, parse.airport_coordinates[route.getDeparture()].second,
    parse.airport_coordinates[route.getArrival()].first, parse.airport_coordinates[route.getArrival()].second);
    REQUIRE(parse.route_distances[route] == distance);
}

TEST_CASE("Parsing routes.dat test 3") {
    Parse parse;
    parse.parseRoutes("data/airports.dat.csv", "data/routes.dat.csv");
    Route route("DOH", "JFK");
    std::map<Route, double, Compare>::iterator it = parse.route_distances.find(route);
    double distance = parse.findRouteDistance(parse.airport_coordinates[route.getDeparture()].first, parse.airport_coordinates[route.getDeparture()].second,
    parse.airport_coordinates[route.getArrival()].first, parse.airport_coordinates[route.getArrival()].second);
    REQUIRE(parse.route_distances[route] == distance);
}

TEST_CASE("Check access to route_distances test 1") {
    Parse p;
    Flights* f = new Flights();
    Route r("BDS", "ZRH");
    std::map<Route, double, Compare>::iterator it = f->route_distances.find(r);
    double dist = p.findRouteDistance(f->airport_coordinates[r.getDeparture()].first, f->airport_coordinates[r.getDeparture()].second,
    f->airport_coordinates[r.getArrival()].first, f->airport_coordinates[r.getArrival()].second);
    REQUIRE(f->route_distances[r] == dist);
}

TEST_CASE("Check access to route_distances test 2") {
    Parse p;
    Flights* f = new Flights();
    Route r("PEM", "CUZ");
    std::map<Route, double, Compare>::iterator it = f->route_distances.find(r);
    double dist = p.findRouteDistance(f->airport_coordinates[r.getDeparture()].first, f->airport_coordinates[r.getDeparture()].second,
    f->airport_coordinates[r.getArrival()].first, f->airport_coordinates[r.getArrival()].second);
    REQUIRE(f->route_distances[r] == dist);
}

TEST_CASE("Check access to route_distances test 3") {
    Parse p;
    Flights* f = new Flights();
    Route r("ASF", "KZN");
    std::map<Route, double, Compare>::iterator it = f->route_distances.find(r);
    double dist = p.findRouteDistance(f->airport_coordinates[r.getDeparture()].first, f->airport_coordinates[r.getDeparture()].second,
    f->airport_coordinates[r.getArrival()].first, f->airport_coordinates[r.getArrival()].second);
    REQUIRE(f->route_distances[r] == dist);
}

TEST_CASE("Checking vertexExists") {
    Flights* flight = new Flights();
    Route route_one("IAH", "BOM");
    Route route_two("PEK", "NBO"); 
    REQUIRE (flight->graph.vertexExists(route_one.getDeparture()) == true);
    REQUIRE (flight->graph.vertexExists(route_one.getArrival()) == true);
    REQUIRE (flight->graph.vertexExists(route_two.getDeparture()) == true);
    REQUIRE (flight->graph.vertexExists(route_two.getArrival()) == true);
}

TEST_CASE("Checking edgeExists") {
    Flights* flight = new Flights();
    Route route_one("ASF", "KZN");
    Route route_two("BDS", "ZRH"); 
    Route route_three("RAO", "SJP");
    Route route_four("JBR", "STL");
    REQUIRE (flight->graph.edgeExists(route_one.getDeparture(), route_one.getArrival()) == true);
    REQUIRE (flight->graph.edgeExists(route_two.getDeparture(), route_two.getArrival()) == true);
    REQUIRE (flight->graph.edgeExists(route_three.getDeparture(), route_three.getArrival()) == true);
    REQUIRE (flight->graph.edgeExists(route_four.getDeparture(), route_four.getArrival()) == true);
    REQUIRE (flight->graph.edgeExists(route_one.getDeparture(), route_two.getDeparture()) == false);
    REQUIRE (flight->graph.edgeExists(route_four.getDeparture(), route_two.getArrival()) == false);
}

TEST_CASE("Checking getEdgeWeight") {
    Parse parse;
    Flights* flight = new Flights();
    Route route_one("DXB", "BOM");
    Route route_two("DEL", "COK"); 
    Route route_three("JFK", "LAX");
    Route route_four("TRV", "COK");

    std::map<Route, double, Compare>::iterator it = flight->route_distances.find(route_one);
    double distance_one = parse.findRouteDistance(flight->airport_coordinates[route_one.getDeparture()].first, flight->airport_coordinates[route_one.getDeparture()].second,
    flight->airport_coordinates[route_one.getArrival()].first, flight->airport_coordinates[route_one.getArrival()].second);

    std::map<Route, double, Compare>::iterator it2 = flight->route_distances.find(route_two);
    double distance_two = parse.findRouteDistance(flight->airport_coordinates[route_two.getDeparture()].first, flight->airport_coordinates[route_two.getDeparture()].second,
    flight->airport_coordinates[route_two.getArrival()].first, flight->airport_coordinates[route_two.getArrival()].second);

    std::map<Route, double, Compare>::iterator it3 = flight->route_distances.find(route_three);
    double distance_three = parse.findRouteDistance(flight->airport_coordinates[route_three.getDeparture()].first, flight->airport_coordinates[route_three.getDeparture()].second,
    flight->airport_coordinates[route_three.getArrival()].first, flight->airport_coordinates[route_three.getArrival()].second);

    std::map<Route, double, Compare>::iterator it4 = flight->route_distances.find(route_four);
    double distance_four = parse.findRouteDistance(flight->airport_coordinates[route_four.getDeparture()].first, flight->airport_coordinates[route_four.getDeparture()].second,
    flight->airport_coordinates[route_four.getArrival()].first, flight->airport_coordinates[route_four.getArrival()].second);

    REQUIRE (flight->graph.getEdgeWeight(route_one.getDeparture(), route_one.getArrival()) == distance_one);
    REQUIRE (flight->graph.getEdgeWeight(route_two.getDeparture(), route_two.getArrival()) == distance_two);
    REQUIRE (flight->graph.getEdgeWeight(route_three.getDeparture(), route_three.getArrival()) == distance_three);
    REQUIRE (flight->graph.getEdgeWeight(route_four.getDeparture(), route_four.getArrival()) == distance_four);
}

TEST_CASE("Checking isValid") {
    Parse parse;
    parse.parseRoutes("data/airports.dat.csv", "data/routes.dat.csv");

    Route route_one("LAX", "DOH");
    Route route_two("BOM", "JFK");

    REQUIRE (parse.isValid(route_one.getDeparture(), route_two.getDeparture()) == true);
    REQUIRE (parse.isValid(route_one.getArrival(), route_two.getArrival()) == true);
    REQUIRE (parse.isValid("ZCY", "AYL") == false);
    REQUIRE (parse.isValid("AYL", "WTL") == false);
}

TEST_CASE("Dijkstra test 1") {
    Flights * flight = new Flights(); 
    Dijkstra dijkstra; 
    Airport one("BOM"); 
    Airport two("COK");
    vector<string> route = dijkstra.dijkstra(flight->graph, one, two); 
    route.push_back(one); 
    std::reverse(route.begin(), route.end());
    vector<string> test; 
    test.push_back("BOM");
    test.push_back("COK");
    REQUIRE(test == route);
}

TEST_CASE("Dijkstra test 2") {
    Flights * flight = new Flights(); 
    Dijkstra dijkstra; 
    Airport one("ORD"); 
    Airport two("BLR");
    vector<string> route = dijkstra.dijkstra(flight->graph, one, two); 
    route.push_back(one); 
    std::reverse(route.begin(), route.end());
    vector<string> test; 
    test.push_back("ORD");
    test.push_back("DEL");
    test.push_back("BLR");
    REQUIRE(test == route);
}

TEST_CASE("Dijkstra test 3") {
    Flights * flight = new Flights(); 
    Dijkstra dijkstra; 
    Airport one("AKL"); 
    Airport two("AGP");
    vector<string> route = dijkstra.dijkstra(flight->graph, one, two); 
    route.push_back(one); 
    std::reverse(route.begin(), route.end());
    vector<string> test; 
    test.push_back("AKL");
    test.push_back("BKK");
    test.push_back("IST");
    test.push_back("AGP");
    REQUIRE(test == route);
}

	
TEST_CASE("Testing Pagerank function top airports") { 
    PageRank *test = new PageRank(); 
    test->list.resize(5);
    test->result.resize(5);

    test->list[0] = 0;
    test->list[1] = 1;
    test->list[2] = 2;
    test->list[3] = 3;
    test->list[4] = 4;

    test->result[0] = 0.245;
    test->result[1] = 324.15;
    test->result[2] = 23.21;
    test->result[3] = 56.33;
    test->result[4] = 4;

    vector<int> rank = test->pick_airport(3); 
    REQUIRE(1 == rank[0]);
    REQUIRE(3 == rank[1]);
    REQUIRE(2 == rank[2]);
}

TEST_CASE("Testing Pagerank function adjacency") {
    PageRank *test = new PageRank();
    int size = 2;
    test->adjacency_vector.resize(size,vector<double>(size));
    test->adjacency_vector[0][0] = 0.0;
    test->adjacency_vector[1][0] = 0.0;
    test->adjacency_vector[0][1] = 4.0;   
    test->adjacency_vector[1][1] = 6.0;  
    test->list.resize(size);
    test->num = size;

    test->PageRank::adjacency(size, 0.85);
    REQUIRE(0.5 == test->adjacency_vector[0][0]);
    REQUIRE(0.5 == test->adjacency_vector[1][0]);
    REQUIRE(1 == test->adjacency_vector[0][1] + test->adjacency_vector[1][1]);
}


TEST_CASE("Testing Pagerank function pr()") { 
    PageRank *test = new PageRank();
    int size = 10;
    test->adjacency_vector.resize(size,vector<double>(size));
    test->list.resize(size);
    test->num = size;
    for (int i = 0; i < size; i++) {
        test->list[i] = i;
        for (int j = 0; j < size; j++) {
            test->adjacency_vector[i][j] = 0.0;
        }        
    }
    test->adjacency_vector[0][1] = 10;
    test->PageRank::adjacency(size, 0.85);
    vector<double> initial = test->PageRank::vec();
    vector<double> temp = test->PageRank::pr(initial, 50, true);
    vector<int> rank = test->pick_airport(1); 
    REQUIRE(0 == rank[0]);
}