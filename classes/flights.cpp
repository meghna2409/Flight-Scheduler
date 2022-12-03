#include <map>
#include <iterator>
#include <iostream>

#include "cs225/HSLAPixel.h"
#include "flights.h"
#include "edge.h"
#include "routes.h"
#include "parse.h"
#include "graph.cpp"
#include "dijkstra.h"

using namespace cs225;
Flights::Flights() : graph(true) {
    Parse p;
    route_distances = p.parseRoutes("data/airports.dat.csv", "data/routes.dat.csv");
    
    for (std::map<Route, double, Compare>::iterator it = route_distances.begin(); it != route_distances.end(); it++) {
        Airport departure = it->first.getDeparture();
        Airport arrival = it->first.getArrival();
        double weight = it->second;

        if (graph.vertexExists(departure) == false) {
            graph.insertVertex(departure);
        }

        if (graph.vertexExists(arrival) == false) {
            graph.insertVertex(arrival);
        }

        Edge edge(departure, arrival, weight, "");
        graph.insertEdge(edge.getDeparture(), edge.getArrival());
        graph.setEdgeWeight(edge.getDeparture(), edge.getArrival(), weight);
        
    }
    airport_coordinates = p.getCoordinates();
}

Flights::~Flights() {
    delete this;
}

void Flights::storeAirportData(std::string departure,std::string arrival) {
    Airport d(departure);
    Airport a(arrival);
    departureID = d;
    arrivalID = a;
}

