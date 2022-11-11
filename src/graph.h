# pragma once
# include "airports.h"

class Graph {
    public:
        Graph() {}
        Graph(std::string & airports, std::string & routes);
        void addVertex(int vertex, Airport airport);
        void addVertices(std::string & airports);
    private:
        std::unordered_map<int, Airport> vertices;
}