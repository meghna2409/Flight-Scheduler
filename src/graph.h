# pragma once

# include "airport.h"
# include <unordered_map>
# include <unordered_set>

using namespace std;
class Graph {
    public:
        Graph() {}
        Graph(std::string & airports, std::string & routes);
        void addVertex(int vertex, Airport airport);
        void addVertices(std::string & airports);
        void addEdges(std::string & routes);
    private:
        std::unordered_map< int, Airport > vertices;
        std::unordered_map< int, unordered_set<int> > graph;
};