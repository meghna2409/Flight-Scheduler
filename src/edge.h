#pragma once

#include <string>
#include <limits.h>

using std::string;

typedef string Airport;

class Edge {
  public:
    // Default constructor
    Edge() : departure_(""), arrival_(""), label(""), weight(-1) { }

    // Parameterized constructor for unweighted graphs with inputs as departure and arrival airports.
    Edge(Airport one, Airport two) : departure_(one), arrival_(two), label(""), weight(-1) { }

    // Parameterized constructor for unweighted graphs with inputs as departure airport, arrival airport, and the edge label.
    Edge(Airport one, Airport two, string label) : departure_(one), arrival_(two), label(label) { }

    // Parameterized constructor for unweighted graphs with inputs as departure airport, arrival airport, edge label, and edge label weight.
    Edge(Airport one, Airport two, double weight, string label) : departure_(one), arrival_(two), label(label), weight(weight) { }

    // Returns the departure airport.
    Airport getDeparture() const {
        return this->departure_;
    }

    // Returns the arrival airport.
    Airport getArrival() const {
        return this->arrival_;
    }

    // Returns edge label.
    std::string getLabel() const {
        return this->label;
    }

    // Returns edge weight.
    double getWeight() const {
        return this->weight;
    }

    // Compares two edge labels' weights.
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }

    // Compares the departure and arrival airports of two edges.
    bool operator==(Edge& other) const {
        if (this->departure_ != other.departure_)
            return false;
        if (this->arrival_ != other.arrival_)
            return false;
        return true;
    }

private:
    // Departure of the edge.
    Airport departure_; 
    // Arrival of the edge.
    Airport arrival_; 
    // The edge label.
    string label; 
    // The edge label's weight.
    double weight; 
};