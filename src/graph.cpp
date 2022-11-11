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
            vector<string> result;
            stringstream s_stream(current);
            while(s_stream.good()) {
                string substr;
                getline(s_stream, substr, ','); //get first string delimited by comma
                result.push_back(substr);
            }
            if (result.size == 13 && result[0] != -1) {
                // change constructor
                Airport airport(result[0], result[1], result[2],);
                addVertex(airport.getID(), airport);
            }
            // what does this do here?
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
    
}