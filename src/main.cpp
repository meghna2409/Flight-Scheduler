#include "graph.h"

#include <iostream>

int main(){
    std::string airportFile = "airports.dat";
    std::string routesFile = "routes.dat";
    Graph g(airportFile, routesFile);

    std::string test_airport = "test_airport.dat";
    Airport airport(test_airport);
    std::cout << "ID: " << airport.getID() << std::endl;
    std::cout << "Name: " << airport.getName() << std::endl;
    std::cout << "City: " << airport.getCity() << std::endl;
    std::cout << "Country: " << airport.getCountry() << std::endl;
    std::cout << "Latitude: " << airport.getLatitude() << std::endl;
    std::cout << "Longitude: " << airport.getLongitude() << std::endl;

    std::string test_graph_airports = "test_graph_airports.dat";
    std::string test_graph_routes = "test_graph_routes.dat";
    Graph graph(test_graph_airports, test_graph_routes);

    std::unordered_map< int, Airport > vertices = graph.getVertices();
    for (std::pair<int, Airport> pair : vertices) {
        std::cout << "Index: " << pair.first << "; Airport: "
        << pair.second.getName() << std::endl;
    }


    return 0;
}