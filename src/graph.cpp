#include "graph.h"

Graph::Graph(std::string & airports, std::string & routes) {
    addVertices(airports);
    addEdges(routes);
}

void Graph::addVertex(int vertex, Airport airport) {
    vertices[vertex] = airport;
}

void Graph::addVertices(std::string & airports) {
    std::fstream file;
    file.open(airports, ios::in);
    if (file.is_open()) {
        std::string current;
        while (getline(file, current)) {
            int num = 0;
            for (unsigned i = 0; i < current.size(); i++) {
                char current_char = current[i];
                if (current_char == ',') {
                    num++;
                }
            }
            if (num == 13) {
                Airport airport(current);
                addVertex(airport.getID(), airport);
            }
        }
        file.close();
    }
}