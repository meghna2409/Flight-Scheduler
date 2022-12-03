#pragma once

#include <string>
#include <utility>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cmath>
#include <fstream>
#include <functional>
#include "edge.h"
#include "routes.h"

// This class allows us to parse through the airports and routes files and store this information so we can use it in the future.
class Parse {
    public:
        // A vector of all routes from routes.dat.
        std::vector<Route> all_routes;

        // A map with routes (key) to their distances (value).
        std::map<Route, double, Compare> route_distances; 

        // A map with airport IDs (key) to their latitude/longitude pair (value).
        std::map<std::string, std::pair<double, double>> airport_coordinates; 

        // Takes in all airports and routes and parses this data to create a vector of all possible edges and a map with all its distances. 
        std::map<Route, double, Compare> parseRoutes(const std::string& airports, const std::string& routes);

        // Takes in all airports and parses this data to creates a map with all airport coordinates. 
        void parseAirports(const string& airports);

        // Converts from degrees to radians.
        double degreesToRadians(double degree);

        // Evaluates the distance of a route and updates the map route_distances accordingly. 
        void findRouteDistance();

        // Takes in departure coordinates and arrival coordinates and evaluates the distance between them. 
        double findRouteDistance(double departure_latitude, double departure_longitude, double arrival_latitude, double arrival_longitude);

        // Checks the validity of the user input (departure and arrival airports).
        bool isValid(const std::string& departure, const std::string& arrival);

        // Returns the airport_coordinates map
        std::map<std::string, std::pair<double, double>> getCoordinates();

    private:
        // Respective columns for various properties in routes.dat and airports.dat.
        int departure_col = 4; 
        int arrival_col = 6; 
        int airline_col = 6;
        int latitude_col = 8; 
        int longitude_col = 9;
};

