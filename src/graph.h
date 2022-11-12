# pragma once

# include "airport.h"
# include <unordered_map>
# include <unordered_set>

using namespace std;
class Graph {
    public:
        /**
         * Constructs an empty graph.
         */
        Graph() {}

        /**
         * Constructs a graph from a string that contains the information 
         * of airports and a string that contains the information of routes.
         * 
         * @param airports the string about airports to read from.
         * @param routes the string about routes to read from.
         */
        Graph(std::string & airports, std::string & routes);

        /**
         * Adds an airport to the specified vertex.
         * 
         * @param vertex the index of the vertex to add the airport.
         * @param routes the airport to add
         */
        void addVertex(int vertex, Airport airport);

        /**
         * Adds vertices from a string that contains the basic information
         * of airports.
         * 
         * @param airports the string to read from.
         */
        void addVertices(std::string & airports);

        /**
         * Adds edges from a string that contains the basic information of
         * routes.
         * 
         * @param routes the string to read from.
         */
        void addEdges(std::string & routes);

        /**
         * Gets the vertices of the graph. Used only for test purposes.
         * 
         * @return vertices of the graph.
         */
        std::unordered_map< int, Airport > getVertices();

    private:
        std::unordered_map< int, Airport > vertices;                /*< Vertices of the graph */
        std::unordered_map< int, unordered_set<int> > graph;        /*< Adjacency list of the graph */
};