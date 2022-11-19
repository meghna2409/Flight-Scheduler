#pragma once
#include "airport.h"
#include "graph.h"
#include "route.h"
#include <unordered_map>
#include <map>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>

class Dijkstra {
	public:
		Airport findMinDistance(unordered_map<string, int> distance, unordered_map<string, bool> visited, int num, vector<Airport> vertices);
		vector<string> recurse(unordered_map<string, string> parent, Airport airport, vector<string> fill_path);
		vector<string> dijkstra(Graph graph, Airport departure, Airport arrival);
	private:
};