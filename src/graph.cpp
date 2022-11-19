# include "graph.h"

#include <cmath>

Graph::Graph(std::string & airports, std::string & routes) {
    addVertices(airports);
    addEdges(routes);
}

void Graph::addVertex(int vertex, Airport airport) {
    vertices[vertex] = airport;
}

void Graph::addVertices(std::string & airports) {
    std::fstream file;
    file.open(airports, std::ios::in);
    if (file.is_open()) {
        std::string current;
        while (getline(file, current)) {
            Airport airport(current);
            addVertex(airport.getID(), airport);
        }
        file.close();
    }
}

void Graph::addEdges(std::string & routes) {
    std::fstream file;
    file.open(routes, std::ios::in);
    if (file.is_open()) {
        std::string current;
        while (getline(file, current)) {
            vector<string> result;
            stringstream s_stream(current);
            while(s_stream.good()) {
                string substr;
                getline(s_stream, substr, ','); // get first string delimited by comma
                result.push_back(substr);
            }
            // What should we do if the id is invalid? Right now, it's just not getting
            // put into the graph.
            try {
                int sourceAirportID = std::stoi(result[3]);
                int destAirportID = std::stoi(result[5]);
                // Put in directed graph. Source -> Destination
                // Check if invalid?
                unordered_map< int, unordered_map<int, Route> >::iterator it = graph.find(sourceAirportID);

                Airport source = vertices.at(sourceAirportID);
                Airport dest = vertices.at(destAirportID);
                double lat1 = source.getLatitude();
                double lat2 = dest.getLatitude();
                double lon1 = source.getLongitude();
                double lon2 = dest.getLongitude();

                double dLat = (lat2 - lat1) * M_PI / 180.0;
                double dLon = (lon2 - lon1) * M_PI / 180.0;
        
                // convert to radians
                lat1 = (lat1) * M_PI / 180.0;
                lat2 = (lat2) * M_PI / 180.0;
        
                // apply formulae
                double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) *
                        cos(lat1) * cos(lat2);
                double rad = 6371;
                double c = 2 * asin(sqrt(a));
                double distance = rad * c;

                Route route(sourceAirportID, destAirportID, distance, "");
                graph[sourceAirportID].insert(std::pair(destAirportID, route));
            } catch (...) {
                cout << "invalid id" << endl;
            }
        }
    }
}

std::unordered_map< int, Airport > Graph::getVertices() {
    return vertices;
}