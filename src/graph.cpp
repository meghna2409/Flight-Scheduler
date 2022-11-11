# include "graph.h"

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
            // what does this do? - Anna
            /*
            for (unsigned i = 0; i < current.size(); i++) {
                char current_char = current[i];
                if (current_char == ',') {
                    num++;
                }
            }
            if (num == 13) {
                // change constructor
                Airport airport;
                addVertex(airport.getID(), airport);
            }
            */
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
                unordered_map< int, unordered_set<int> >::iterator it = graph.find(sourceAirportID);
                graph[sourceAirportID].insert(destAirportID);
            } catch (...) {
                cout << "invalid id" << endl;
            }
        }
    }
}