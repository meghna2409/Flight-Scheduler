#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>


#include "../src/airport.h"
#include "../src/graph.h"
#include "../src/route.h"
#include "../src/dijkstra.h"
#include "../catch/catch.hpp"


using namespace std;
TEST_CASE("Testing Airport constructor with vector") { 
    unordered_map<string, Airport> vertices;
    cout << "Testing vector constructor with Chicago O'Hare International Airport" << endl;
    vector<string> airport_data = {"3830","Chicago O'Hare International Airport","Chicago","United States", "ORD", "KORD", "41.9786", "-87.9048", "672", "-6", "A", "America/Chicago", "airport", "OurAirports"};
    vertices["Chicago O'Hare International Airport"] = Airport(atof(airport_data[0].c_str()), airport_data[1], airport_data[2], airport_data[3], atof(airport_data[6].c_str()), atof(airport_data[7].c_str()));
    int id = vertices["Chicago O'Hare International Airport"].getID();
    string name = vertices["Chicago O'Hare International Airport"].getName();
    string city = vertices["Chicago O'Hare International Airport"].getCity();
    string country = vertices["Chicago O'Hare International Airport"].getCountry();
    double latitude = (double)vertices["Chicago O'Hare International Airport"].getLatitude();
    double longitude = (double)vertices["Chicago O'Hare International Airport"].getLongitude();

    REQUIRE(3830 == id);
    REQUIRE("Chicago O'Hare International Airport" == name);
    REQUIRE("Chicago" == city);
    REQUIRE("United States" == country);
    REQUIRE(41.9786 == latitude);
    REQUIRE(-87.9048 == longitude);
}

TEST_CASE("Testing Airport constructor with string") { 
    cout << "Testing string constructor with Chicago O'Hare International Airport" << endl;
    unordered_map<string, Airport> vertices;
    string ohare = "\"3830\", \"Chicago O'Hare International Airport\", \"Chicago\", \"United States\", \"ORD\", \"KORD\", \"41.9786\", \"-87.9048\", \"672\", \"-6\", \"A\", \"America/Chicago\" , \"airport\", \"OurAirports\"";
    vertices["Chicago O'Hare International Airport"] = Airport(ohare);
    int id = (vertices["Chicago O'Hare International Airport"].getID());
    string name = (vertices["Chicago O'Hare International Airport"].getName());
    string city = (vertices["Chicago O'Hare International Airport"].getCity());
    string country = (vertices["Chicago O'Hare International Airport"].getCountry());
    double latitude = (double)vertices["Chicago O'Hare International Airport"].getLatitude();
    double longitude = (double)vertices["Chicago O'Hare International Airport"].getLongitude();
    
    REQUIRE(3830 == id);
    REQUIRE("Chicago O'Hare International Airport" == name);
    REQUIRE("Chicago" == city);
    REQUIRE("United States" == country);
    REQUIRE(41.9786 == latitude);
    REQUIRE(-87.9048 == longitude);
}

TEST_CASE("Testing constructing whole graph") {
    string airports = "airports.dat";
    string routes = "routes.dat";
    Graph graph(airports, routes);
    unordered_map<int, Airport> map = graph.getVertices();
    cout << "Number of airports: " << map.size() << endl;
    // Printing all flights departing from O'Hare, Dubai, and Trivandrum airport
    for (auto it = map.begin(); it != map.end(); ++it){
        if (it->first == 3830 || it->first == 2188 || it->first == 3153) {
            cout << "Airport ID: " <<it->second.getID() << " ";
            cout << "Airport Name: " <<it->second.getName() << endl;
            unordered_map<int, Route> adjacency_list = it->second.connected_airports;
            for (auto it = adjacency_list.begin(); it != adjacency_list.end(); ++it) {
                cout << "Source ID: " << it->second.getSourceID() << " ";
                cout << "Destination ID: " << it->second.getDestID() << " ";
                cout << "Flight weight: " << it->second.getWeight() << endl;
            }
        }
    }
    REQUIRE(7000 <= map.size());
}
