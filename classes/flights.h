#pragma once

#include <map>
#include <iterator>
#include <iostream>
#include <unordered_map>
#include "edge.h"
#include "parse.h"
#include "graph.h"
#include "routes.h"
#include "dijkstra.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

class Flights {
    public:
    // Map of airport IDs to their latitude/longitude(pair).
    std::map<std::string, std::pair<double, double>> airport_coordinates; 

    // Map of routes to their distances.
    std::map<Route, double, Compare> route_distances; 
    
    Graph graph; 

    // Default constructor for the graph.
    Flights();

    // Destructor
    ~Flights();

    // Stores departure and arrival airports.
    void storeAirportData(std::string userSource, std::string userDestination);
  
    private:
        Airport departureID; 
        Airport arrivalID; 
};