#pragma once
#include "flights.h"
#include "parse.h"
#include "graph.h"
#include "edge.h"
#include <unordered_map>
#include <iterator>
#include <iostream>
#include <vector>

class Dijkstra {
	public:
		// Returns the airport closest to the current airport. 
		Airport findNearby(unordered_map<string, int> distance, unordered_map<string, bool> visited, int current_vertex, vector<Airport> vertices);

		// Shows the path from departure to arrival. 
		vector<string> recurse(unordered_map<string, string> parent, Airport airport, vector<string> fill_path);

		// Prints the final flight path.
		vector<string> print(unordered_map<string, int> distance, int n, unordered_map<string, string> parent, vector<Airport> vertices, Airport departure, Airport arrival, vector<string> fill_path);

		// Use of dijkstra's algorithm to find the shortest path between two airports. 
		vector<string> dijkstra(Graph graph, Airport departure, Airport arrival);

	private:

};