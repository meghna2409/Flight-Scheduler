#pragma once

#include <set>
#include <list>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "edge.h"
#include "random.h"

using namespace std;

class Graph {
public:
    // Parameterized constructor to create an empty graph (weighted/unweighted). 
    Graph(bool weighted) : weighted(weighted), directed(false), random(Random(0)) { }

    // Parameterized constructor to create an empty graph (weighted/unweighted and directed/undirected).
    Graph(bool weighted, bool directed) : weighted(weighted), directed(directed), random(Random(0)) { }

    // Parameterized constructor to create a random graph using a random seed (weighted/unweighted).
    Graph(bool weighted, int num_vertices, unsigned long seed);

    // Returns all adjacent vertices.
    vector<Airport> getAdjacent(Airport departure) const;

    // Returns one airport from the graph.
    Airport getVertex() const;

    // Returns all airports from the graph.
    vector<Airport> getVertices() const;

    // Returns the edge between two airports.
    Edge getEdge(Airport departure, Airport arrival) const;

    // Returns all edges from the graph.
    vector<Edge> getEdges() const;

    // Check if an airport exists.
    bool vertexExists (Airport v) const;

    // Check if an edge between two airports exists.
    bool edgeExists(Airport departure, Airport arrival) const;

    // Sets the edge label between two airports.
    Edge setEdgeLabel(Airport departure, Airport arrival, string label);

    // Gets the edge label between two airports.
    string getEdgeLabel(Airport departure, Airport arrival) const;

    // Gets the weight of the edge between two airports.
    double getEdgeWeight(Airport source, Airport destination) const;

    // Inserts a new airport into the graph.
    void insertVertex(Airport v);

    // Removes an airport from the graph.
    Airport removeVertex(Airport v);

    // Inserts an edge between two airports.
    bool insertEdge(Airport departure, Airport arrival);

    // Removes an edge between two airports.
    Edge removeEdge(Airport source, Airport destination);

    // Sets the weight of the edge between two airports.
    Edge setEdgeWeight(Airport source, Airport destination, double weight);

    // Prints the graph.
    void print() const;

    // Checks if the graph is directed or undirected.
    bool isDirected() const;

    // Clears the adjacency list.
    void clear();

    const Edge invalid_edge = Edge("Invalid Vertex", "Invalid Vertex", INT_MIN, "Invalid Label");

private:
    mutable unordered_map<Airport, unordered_map<Airport, Edge>> adjacency_list;
    bool weighted;
    bool directed;
    Random random;

    // Returns whether an airport exists in the graph. Takes in the name of a function as a parameter to return if we encounter an error.
    bool doesVertexExist(Airport airport, string function) const;

    // Returns whether an edge exists in the graph. Takes in the name of a function as a parameter to return if we encounter an error.
    bool doesEdgeExist(Airport departure, Airport arrival, string function) const;

    // Prints a graph error and quits the program.
    void error(string message) const;
};