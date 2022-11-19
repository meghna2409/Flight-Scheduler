#include "dijkstra.h"
using namespace std;


Airport Dijkstra::findMinDistance(unordered_map<string, int> distance, unordered_map<string, bool> visited, int num, vector<Airport> vertices) { 
    int min = INT_MAX;
    int index; 
    for (int i = 0; i < num; i++) 
        if (visited[vertices[i]] == false && distance[vertices[i]] <= min)  {
            min = distance[vertices[i]];
            index = i; 
        }
    return vertices[index]; 
} 

vector<string> Dijkstra::recurse(unordered_map<string, string> parent, Airport airport, vector<Airport> fill_path) { 
    if (parent[airport] == "-1") return fill_path;
    fill_path.push_back(airport);
    return recurse(parent, parent[airport], fill_path); 
} 

vector<string> Dijkstra::dijkstra(Graph graph, Airport departure, Airport arrival) {
	unordered_map<string, int> distances;
	unordered_map<string, bool> visited;
	unordered_map<string, string> parent;
    vector<string> fill_path;
	parent[departure] = "-1";
	vector<Airport> vertices = graph.getVertices();

    for (int i = 0; i < vertices.size(); i++) { 
        distances[vertices[i]] = INT_MAX; 
        visited[vertices[i]] = false; 
    }
    int num = vertices.size();
    distances[departure] = 0; 
    for (int j = 0; j < num - 1; j++) {  
        Airport a = findMinDistance(distances, visited, num, vertices); 
        visited[a] = true;  
        // for (int k = 0; k < num; k++) {
        //     if (!visited[vertices[k]] && graph.edgeExists(k, vertices[k])) {
        //         if (distances[a] + graph.getWeight(k, vertices[k]) < distances[vertices[k]]) {
        //             parent[vertices[k]] = a; 
        //             distances[vertices[k]] = distances[k] + graph.getWeight(k, vertices[k]); 
        //         }
        //     }
        // }   
    }
    // return print(distances, num, parent, vertices, departure, arrival, fill_path); 
} 