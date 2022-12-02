#pragma once
#include "Airport.h"
#include "Graph.h"
#include "Route.h"

#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Dijkstra {
    public:
        Dijkstra(Graph graph, string departure_airport, string arrival_airport);
        double getShortestDistance() const;
        vector<string> getPathVertices() const;
        vector<pair<int, double>> getAdjacent(string departure_airport);
        bool vertexExists(string vertex);

    private:
	    double path;
        map<string, double> distances;
		vector<string> path_vertices;
		unordered_map <string, bool> visited; 
        unordered_map<string, string> passed_airports;
        unordered_map<string, unordered_map<int, Route> > adjacency_list;
		priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> queue;
};