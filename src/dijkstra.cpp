#include "Dijkstra.h"
#include <map>
#include <climits>
#include <stack>

using namespace std;

Dijkstra::Dijkstra(Graph graph, string departure_airport, string arrival_airport) {
    path_vertices.clear();
    vector<string> airports;  
    unordered_map<int, Airport> map = graph.getVertices();

    for (auto it = map.begin(); it != map.end(); ++it) {
        airports.push_back(it->second.getName());
        passed_airports.insert(make_pair(it->second.getName(), ""));
        visited.insert(make_pair(it->second.getName(), false));
        if (it->second.getName() == departure_airport) distances.insert(make_pair(it->second.getName(), 0.0));
        else distances.insert(make_pair(it->second.getName(), INT_MAX));
    }

    queue.push(make_pair(0.0, departure_airport));
    for (auto it = map.begin(); it != map.end(); ++it) {
        adjacency_list.insert(make_pair(it->second.getName(), it->second.connected_airports));
    }

    while(queue.top().second != arrival_airport) {
        pair<double, string> current = queue.top();
        queue.pop();
        vector<pair<int , double>> neighbors = getAdjacent(current.second);
        vector<pair<string, double>> names;
        for (auto n : neighbors) {
            for (auto it = map.begin(); it != map.end(); ++it) {
                if (n.first == it->first) {
                    names.push_back(make_pair(it->second.getName(), n.second));
                }
            }
        }

        for (auto m : names) {
            if (visited[m.first] == false && visited[current.second] == false) {
                if (m.second + distances[current.second] < distances[m.first]) {
                    distances[m.first] = m.second + distances[current.second];
                    passed_airports[m.first] = current.second;
                    queue.push(make_pair(distances[m.first], m.first)); 
                }
            }
        }

        visited[current.second] = true;
    }
 
    path = distances[arrival_airport];

    string key = arrival_airport;
    path_vertices.push_back(arrival_airport);
    while(key != departure_airport) {
        path_vertices.push_back(passed_airports[key]);
        key = passed_airports[key];
    }
    std::reverse(path_vertices.begin(), path_vertices.end());
}

bool Dijkstra::vertexExists(string node) {
    if (adjacency_list.find(node) == adjacency_list.end()) {
        return false;
    }
    return true;
}

double Dijkstra::getShortestDistance() const {
  return path;
}

vector<string> Dijkstra::getPathVertices() const {
  return path_vertices;
}

vector<pair<int, double>> Dijkstra::getAdjacent(string source) {
    auto find = adjacency_list.find(source);
    vector<string> result;

    if (find == adjacency_list.end()) return vector<pair<int,double>>();
    else {
        vector<pair<int,double>> vertex_list;
        unordered_map<int, Route> &map = adjacency_list.at(source);
        for (auto it = map.begin(); it != map.end(); it++) {
            vertex_list.push_back(make_pair(it->first, it->second.getWeight()));
        }
        return vertex_list;
    }
}