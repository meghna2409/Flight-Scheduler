#pragma once

#include <iostream>
#include <functional>
#include "edge.h"

class Route {
public:
    // Default constructor.
    Route() : departure_(""), arrival_("") {}

    // Creates a route with the provided departure and arrival airports.
    Route(Airport departure, Airport arrival) : departure_(departure), arrival_(arrival) {}

    // Sets departure airport.
    void setDeparture(Airport departure) {
        departure_ = departure;
    }

    // Sets arrival airport.
    void setArrival(Airport arrival) {
        arrival_ = arrival;
    }

    // Returns departure airport.
    Airport getDeparture() const {
        return departure_;
    }

    // Returns arrival airport.
    Airport getArrival() const {
        return arrival_;
    }

    // Compares two routes.
    bool operator==(const Route& other) const {
        return (this->getDeparture() == other.getDeparture() &&
        this->getArrival() == other.getArrival());
    }

private:
    // Departure airport in the route.
    Airport departure_; 
    // Arrival airport in the route.
    Airport arrival_; 
};

// Sort map by departure airport.
struct Compare {
   bool operator() (const Route& one, const Route& two) const {
       if (one.getDeparture() != two.getDeparture()) {
        return one.getDeparture() < two.getDeparture();
       } else {
           return one.getArrival() < two.getArrival();
       }
   }
};