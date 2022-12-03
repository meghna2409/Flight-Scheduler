#include "graph.h"

Graph::Graph(bool weighted, int num_vertices, unsigned long seed) : weighted(weighted), directed(false), random(Random(seed)) {
    // Check if there are enough airports in the graph.
    if (num_vertices <= 1) {
        error("There are not enough airports in the graph.");
        exit(1);
    }

    // Store all of the vertices in a vector. 
    vector<Airport> vertices;
    for (int i = 0; i < num_vertices; i++) {
        insertVertex(to_string(i));
        vertices.push_back(to_string(i));
    }

    // Check if all of the vertices are connected.
    // Shuffle/randomize the vertices vector.
    random.shuffle(vertices);
    // Set current equal to the first vertex.
    Airport current = vertices[0];
    // Loop through vertices.
    for (unsigned j = 0; j < vertices.size() - 1; j++) {
        // Insert edges accordingly.
        Airport next = vertices[j + 1];
        insertEdge(current, next);
        // If weighted, insert the edge weight.
        if (weighted == true) {
            int weight = random.nextInt();
            setEdgeWeight(current, next, weight);
        }
        current = next;
    }

    // Prevent the graph from having too many edges.
    int edges_not_in_graph = 0;
    int count = 0;
    // Shuffle/randomize the vertices vector.
    random.shuffle(vertices);
    while (edges_not_in_graph <= 1) {
        // Check if edge already exists in the graph. If it doesn't, increment edges_not_in_graph.
        if (insertEdge(vertices[count], vertices[count + 1]) == false) {
            edges_not_in_graph++;
        } else {
            // If all edges exist in the graph, set edge weights as needed.
            if (weighted == true) {
                setEdgeWeight(vertices[count], vertices[count + 1], random.nextInt());
            }
            // Increment the index.
            count++;
            if (count >= num_vertices - 2) {
                count = 0;
                random.shuffle(vertices);
            }
        }
    }
}

vector<Airport> Graph::getAdjacent(Airport departure) const {
    if (adjacency_list.find(departure) == adjacency_list.end()) {
        return vector<Airport>();
    } else {
        vector<Airport> adjacent;
        unordered_map <Airport, Edge> & map = adjacency_list[departure];
        for (auto it = map.begin(); it != map.end(); it++) {
            adjacent.push_back(it->first);
        }
        return adjacent;
    }
}


Airport Graph::getVertex() const {
    return adjacency_list.begin()->first;
}

vector<Airport> Graph::getVertices() const {
    vector<Airport> to_return;
    for (auto it = adjacency_list.begin(); it != adjacency_list.end(); it++) {
        to_return.push_back(it->first);
    }
    return to_return;
}

Edge Graph::getEdge(Airport departure, Airport arrival) const {
    if (doesEdgeExist(departure, arrival, "getEdge") == false) {
        return Edge();
    }
    return adjacency_list[departure][arrival];
}

vector<Edge> Graph::getEdges() const {
    if (adjacency_list.empty()) {
        return vector<Edge>();
    }

    vector<Edge> to_return;
    set<pair<Airport, Airport>> visited;

    for (auto iterator_one = adjacency_list.begin(); iterator_one != adjacency_list.end(); iterator_one++) {
        Airport departure = iterator_one->first;
        for (auto iterator_two = adjacency_list[departure].begin(); iterator_two != adjacency_list[departure].end(); iterator_two++) {
            Airport arrival = iterator_two->first;
            if (visited.find(make_pair(departure, arrival)) == visited.end()) {
                to_return.push_back(iterator_two->second);
                visited.insert(make_pair(departure, arrival));
                if (directed == false) {
                    visited.insert(make_pair(departure, arrival));
                }
            }
        }
    }
    return to_return;
}

bool Graph::vertexExists(Airport airport) const {
    return doesVertexExist(airport, "");
}

bool Graph::edgeExists(Airport departure, Airport arrival) const {
    return doesEdgeExist(departure, arrival, "");
}

Edge Graph::setEdgeLabel(Airport source, Airport destination, string label) {
    if (doesEdgeExist(source, destination, "setEdgeLabel") == false) {
        return invalid_edge;
    }
    Edge edge = adjacency_list[source][destination];
    Edge new_edge(source, destination, edge.getWeight(), label);
    adjacency_list[source][destination] = new_edge;

    if (directed == false) {
        Edge reverse(destination,source, edge.getWeight(), label);
        adjacency_list[destination][source] = reverse;
    }
    return new_edge;
}


string Graph::getEdgeLabel(Airport source, Airport destination) const {
    if (doesEdgeExist(source, destination, "getEdgeLabel") == false) {
        return "Invalid Label.";
    } else {
        return adjacency_list[source][destination].getLabel();
    }
}

double Graph::getEdgeWeight(Airport source, Airport destination) const {
    if (weighted == false) {
        error("Cannot get edge weights on unweighted graphs.");
    }

    if (doesEdgeExist(source, destination, "getEdgeLabel") == false) {
        return INT_MIN;
    } else {
        return adjacency_list[source][destination].getWeight();
    }
}

void Graph::insertVertex(Airport airport) {
    removeVertex(airport);
    adjacency_list[airport] = unordered_map<Airport, Edge>();
}


Airport Graph::removeVertex(Airport airport) {
    if (adjacency_list.find(airport) != adjacency_list.end()) {
        if (directed == false) {
            for (auto iterator_one = adjacency_list[airport].begin(); iterator_one != adjacency_list[airport].end(); iterator_one++) {
                Airport temp = iterator_one->first;
                adjacency_list[temp].erase(airport); 
            }
            adjacency_list.erase(airport);
            return airport;
        }
        
        adjacency_list.erase(airport);
        for (auto iterator_two = adjacency_list.begin(); iterator_two != adjacency_list.end(); iterator_two++) {
            if (iterator_two->second.find(airport) != iterator_two->second.end()) {
                iterator_two->second.erase(airport);
            }
        }
        return airport;
    }
    return "Invalid Vertex.";
}

bool Graph::insertEdge(Airport departure, Airport arrival) {
    // Check if the edge already exists.
    if (adjacency_list.find(departure)!= adjacency_list.end() && adjacency_list[departure].find(arrival)!= adjacency_list[departure].end()) {
        return false;
    }

    if (adjacency_list.find(departure) == adjacency_list.end()) {
        adjacency_list[departure] = unordered_map<Airport, Edge>();
    }

    adjacency_list[departure][arrival] = Edge(departure, arrival);
    if (directed == false) {
        if (adjacency_list.find(arrival)== adjacency_list.end()) {
            adjacency_list[arrival] = unordered_map<Airport, Edge>();
        }
        adjacency_list[arrival][departure] = Edge(departure, arrival);
    }
    
    return true;
}

Edge Graph::removeEdge(Airport departure, Airport arrival) {
    if (doesEdgeExist(departure, arrival, "removeEdge") == false) {
        return invalid_edge;
    }

    Edge edge = adjacency_list[departure][arrival];
    adjacency_list[departure].erase(arrival);
    if (directed == false) {
        adjacency_list[arrival].erase(departure);
    }

    return edge;
}


Edge Graph::setEdgeWeight(Airport departure, Airport arrival, double weight) {
    if (doesEdgeExist(departure, arrival, "setEdgeWeight") == false) {
        return invalid_edge;
    }

    Edge edge = adjacency_list[departure][arrival];
    Edge new_edge(departure, arrival, weight, edge.getLabel());
    adjacency_list[departure][arrival] = new_edge;

    if (directed == false) {
        Edge reverse(arrival, departure, weight, edge.getLabel());
            adjacency_list[arrival][departure] = reverse;
    }

    return new_edge;
}

bool Graph::doesVertexExist(Airport airport, string function) const {
    if (adjacency_list.find(airport) == adjacency_list.end()) {
        if (function != "")
            error(function + " called on vertices that do not exist.");
        return false;
    }
    return true;
}

bool Graph::doesEdgeExist(Airport departure, Airport arrival, string function) const {
    if (doesVertexExist(departure, function) == false) {
        return false;
    }

    if (adjacency_list[departure].find(arrival) == adjacency_list[departure].end()) {
        if (function != "")
            error(function + " called on an edge that does not exist: " + departure + " -> " + arrival);
        return false;
    }

    if (directed == false) {
        if (doesVertexExist(arrival, function) == false) {
            return false;
        }

        if (adjacency_list[arrival].find(departure) == adjacency_list[arrival].end()) {
            if (function != "") {
                error(function + " called on an edge that does not exist: " + arrival + " -> " + departure);
            }
            return false;
        }
    }
    return true;
}

bool Graph::isDirected() const {
    return directed;
}

void Graph::clear() {
    adjacency_list.clear();
}

void Graph::error(string message) const {
    cerr << "\033[1;31m[Graph Error]\033[0m " + message << endl;
}

void Graph::print() const {
    for (auto it = adjacency_list.begin(); it != adjacency_list.end(); ++it) {
        cout << it->first << endl;
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
            std::stringstream ss;
            ss << it2->first; 
            string col = "    => " + ss.str();
            col += " " ;
            cout << std::left << std::setw(26) << col;
            string edgeColumn = "edge label = \"" + it2->second.getLabel()+ "\"";
            cout << std::left << std::setw(26) << edgeColumn;
            if (weighted)
                cout << "weight = " << it2->second.getWeight();
            cout << endl;
        }
        cout << endl;
    }
}