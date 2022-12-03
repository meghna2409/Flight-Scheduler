#include <unordered_map>
#include <iterator>
#include <iostream>
#include <vector>

#include "dijkstra.h"
using namespace std;

Airport Dijkstra::findNearby(unordered_map<string, int> distance, unordered_map<string, bool> visited, int airportent_vertex, vector<Airport> vertices) { 
    int min = INT_MAX;
    int min_index; 
    for (int v = 0; v < airportent_vertex; v++) 
        if (visited[vertices[v]] == false && distance[vertices[v]] <= min)  {
            min = distance[vertices[v]];
            min_index = v; 
        }
    return vertices[min_index]; 
} 

vector<string> Dijkstra::recurse(unordered_map<string, string> parent, Airport airport, vector<string> fill_path) { 
    if (parent[airport] == "-1") {
        return fill_path;
    }
    fill_path.push_back(airport);
    return recurse(parent, parent[airport], fill_path); 
} 

vector<string> Dijkstra::print(unordered_map<string, int> distance, int n, unordered_map<string, string> parent, vector<Airport> vertices, Airport departure, Airport arrival, vector<string> fill_path) { 
    for (int i = 1; i < n; i++) { 
        if (vertices[i] == arrival) {
            std::cout << "Flight Information: \n" << std::endl;
            cout << departure << " -> " << vertices[i] << "   Total Distance: " <<  distance[vertices[i]]
             << "km \n" << endl;
        }
    }
    return recurse(parent, arrival, fill_path); 
} 

vector<string> Dijkstra::dijkstra(Graph graph, Airport departure, Airport arrival) { 
	unordered_map<string, int> distance;
	unordered_map<string, bool> visited;
	unordered_map<string, string> parent;
    vector<string> fill_path;
	parent[departure] = "-1";
	vector<Airport> vertices = graph.getVertices();

    for (unsigned i = 0; i < vertices.size(); i++) { 
        distance[vertices[i]] = INT_MAX; 
        visited[vertices[i]] = false; 
    }
    distance[departure] = 0; 
    for (unsigned j = 0; j < vertices.size() - 1; j++) {  
        string nearby_airport = findNearby(distance, visited, vertices.size(), vertices); 
        visited[nearby_airport] = true;  
        for (unsigned k = 0; k < vertices.size(); k++) {
            if (!visited[vertices[k]] && graph.edgeExists(nearby_airport, vertices[k])) {
                if (distance[nearby_airport] + graph.getEdgeWeight(nearby_airport, vertices[k]) < distance[vertices[k]]) {
                    parent[vertices[k]] = nearby_airport; 
                    distance[vertices[k]] = distance[nearby_airport] + graph.getEdgeWeight(nearby_airport, vertices[k]); 
                }
            }
        }   
    }
    return print(distance, vertices.size(), parent, vertices, departure, arrival, fill_path); 
} 