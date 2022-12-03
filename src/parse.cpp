#include "parse.h"

using namespace std;

std::map<Route, double, Compare> Parse::parseRoutes(const string& airports, const string& routes) {
    string line;
    ifstream file(routes);
    if (file.is_open()) {
        int rows = 1; 
        int column = 1;

        while (getline(file, line)) { 
            string departureID = "";
            Airport departure = "";
            string arrivalID = "";
            Airport arrival = "";
            string delimiter = ",";
            size_t char_count = 0;
            int comma_count = 0; 

            while ((char_count = line.find(delimiter)) != std::string::npos) {
                comma_count++;

                // Find out which column number we are working with. 
                if (comma_count == departure_col - 1) {
                    column = departure_col;
                } else if (comma_count == arrival_col - 1) {
                    column = arrival_col; 
                } else {
                    column = 0;
                }
                
                // Check if the column is departure or arrival. 
                if (column == departure_col) {
                    departureID = line.substr(0, char_count);
                    departure = departureID; 
                } else if (column == arrival_col) {
                    arrivalID = line.substr(0, char_count);
                    arrival = arrivalID; 
                }

                // Add route.
                if (departure != "" && arrival != "") {
                    Route route(departure, arrival);
                    all_routes.push_back(route);
                    break;
                }

                line.erase(0, char_count + delimiter.length());
            }
            rows++;
        }
    }
    file.close();
    parseAirports(airports);
    findRouteDistance();
    return route_distances;
}

void Parse::parseAirports(const string& airports) {
    string line;
    ifstream file(airports);
    if (file.is_open()) {
        int rows = 1; 
        int column = 1;

        while (getline(file, line)) { 
            string ID; 
            double airline_latitude = 0.0; 
            double airline_longitude = 0.0;
            string delimiter = ",";
            size_t char_count = 0;
            int comma_count = 0; 

            while ((char_count = line.find(delimiter)) != std::string::npos) {
                comma_count++;
                std::string current = line.substr(0, char_count);

                int quote_count = 0;
                for (unsigned i = 0; i < current.size(); i++) {
                    if (current.at(i) == '"') {
                        quote_count++;
                    }
                }

                if (quote_count % 2 != 0) {
                    comma_count--;
                }

                // Find out which column number we are working with. 
                if (comma_count == airline_col - 1) {
                    column = airline_col; 
                } else if (comma_count == latitude_col - 1) {
                    column = latitude_col;
                } else if (comma_count == longitude_col - 1) {
                    column = longitude_col; 
                } else {
                    column = 0;
                }

                if (column == airline_col) {
                    ID = line.substr(1, char_count - 2);
                } else if (column == latitude_col) {
                    // Converting string to double.
                    airline_latitude = std::stod(line.substr(0, char_count));
                } else if (column == longitude_col) {
                    // Converting string to double.
                    airline_longitude = std::stod(line.substr(0, char_count));
                }

                // Latitude/longitude pair.
                std::pair<double, double> coordinates;
                coordinates = std::make_pair(airline_latitude, airline_longitude);
                airport_coordinates[ID] = coordinates;
                line.erase(0, char_count + delimiter.length());
            }
            rows++;
        }
    }
    file.close();
}

double Parse::degreesToRadians(double degree) {
    return ((M_PI / 180) * degree); 
} 


void Parse::findRouteDistance()  {
    for (auto route : all_routes) {
        double departure_latitude = airport_coordinates[route.getDeparture()].first;
        double departure_longitude = airport_coordinates[route.getDeparture()].second;
        double arrival_latitude = airport_coordinates[route.getArrival()].first; 
        double arrival_longitude = airport_coordinates[route.getArrival()].second;
        double distance = findRouteDistance(departure_latitude, departure_longitude, arrival_latitude, arrival_longitude);
        route_distances.insert(std::pair<Route, double>(route, distance));
    }
}

double Parse::findRouteDistance(double departure_latitude, double departure_longitude, double arrival_latitude, double arrival_longitude) {
    departure_latitude = degreesToRadians(departure_latitude); 
    departure_longitude = degreesToRadians(departure_longitude); 
    arrival_latitude = degreesToRadians(arrival_latitude); 
    arrival_longitude = degreesToRadians(arrival_longitude); 
    double distance = pow(sin((arrival_latitude - departure_latitude) / 2), 2) +  
                          cos(departure_latitude) * cos(arrival_latitude) *  
                          pow(sin((arrival_longitude - departure_longitude) / 2), 2); 
    distance = 2 * asin(sqrt(distance)) * 6371;
    return distance;
}

bool Parse::isValid(const std::string& departure, const std::string& arrival) {
    bool valid_departure = false;
    bool valid_arrival = false;

    if (departure.size() != 3 || arrival.size() != 3) {
        return false;
    }
    if (airport_coordinates.find(departure) != airport_coordinates.end()) {
        valid_departure = true;
    }

    if (airport_coordinates.find(arrival) != airport_coordinates.end()) {
        valid_arrival = true;
    }

    if (valid_departure && valid_arrival) {
        return true;
    }
    return false;
}
std::map<std::string, std::pair<double, double>> Parse::getCoordinates() {
    return airport_coordinates;
}