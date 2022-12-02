# include "Graph.h"

# include <cmath>

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
                graph[sourceAirportID].insert(std::pair<int, Route>(destAirportID, route));
            } catch (...) {
                cout << "invalid id" << endl;
            }
        }
    }
}

std::unordered_map< int, Airport > Graph::getVertices() {
    return vertices;
}

void Graph::insertEdge(Route route) {       
    int source = route.getSourceID();
    int dest = route.getDestID();

    // Find function returns the key of the desired element or the end iterator if the element is not found
    // Only inserts when the flight does not exist in the adjacency list of the airport
    if (vertices[source].connected_airports.find(dest) == vertices[source].connected_airports.end())   
        (vertices[source].connected_airports)[dest] = route;
}


vector<Airport> Graph::getComponent(Airport airport) {
    vector< Airport > connected;
    map< int, bool > visited;
    DFS(airport, visited, connected);
    return connected;
}

void Graph::DFS(Airport & airport, map< int, bool > & visited, vector< Airport > & connected) {
    connected.push_back(airport);

    int id = airport.getID();
    visited[id] = true;

    unordered_map<int, Route>::iterator it;
    for (it = graph[id].begin(); it != graph[id].end(); ++it) {
        if (!visited[it->first])
            DFS(vertices[id], visited, connected);
    }
}