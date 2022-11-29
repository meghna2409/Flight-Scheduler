# pragma once

# include "airport.h"
# include "route.h"
# include <unordered_map>
# include <unordered_set>
# include <map>
# include <utility>

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

        /**
         * Gets all the airports connected to the passed airport.
         * 
         * @param airport the airport to get connected airports from.
         * @return vector of airports conneted to airport.
         */
        vector<Airport> getComponent(Airport airport);
        void insertEdge(Route route);

    private:
        /**
         * Private helper recursive DFS for getComponent
         * 
         * @param airport the airport to get connected airports from.
         * @param visited the airport ids that have been visited.
         * @param connected the airports connected to the passed in airport.
         */
        void DFS(Airport & airport, map< int, bool > & visited, vector<airport> & connected);

        std::unordered_map< int, Airport > vertices;                /*< Vertices of the graph */
        std::unordered_map< int, unordered_map<int, Route> > graph;        /*< Adjacency list of the graph */
};