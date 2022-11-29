#include "./src/graph.h"
#include "./src/route.h"
#include "./src/airport.h"
# include <unordered_map>
# include <utility>
#include <iostream>

int main() {
    // Testing branches

    std::string airportFile = "../data/airports.dat";
    std::string routesFile = "../data/routes.dat";
    Graph g(airportFile, routesFile);

    std::string test_airport = "../tests/test_airport.dat";
    Airport airport(test_airport);
    std::cout << "ID: " << airport.getID() << std::endl;
    std::cout << "Name: " << airport.getName() << std::endl;
    std::cout << "City: " << airport.getCity() << std::endl;
    std::cout << "Country: " << airport.getCountry() << std::endl;
    std::cout << "Latitude: " << airport.getLatitude() << std::endl;
    std::cout << "Longitude: " << airport.getLongitude() << std::endl;

    std::string test_graph_airports = "../tests/test_graph_airports.dat";
    std::string test_graph_routes = "../tests/test_graph_routes.dat";
    Graph graph(test_graph_airports, test_graph_routes);

    std::unordered_map< int, Airport > vertices = graph.getVertices();
    for (std::pair<int, Airport> pair : vertices) {
        std::cout << "Index: " << pair.first << "; Airport: "
        << pair.second.getName() << std::endl;
    }


    return 0;
}