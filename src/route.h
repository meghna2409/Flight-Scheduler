#pragma once

#include "airport.h"

#include <string>
#include <limits.h>

class Route
{
  public:
    Airport source; /**< The source of the route **/
    Airport dest; /**< The destination of the route **/

    /**
     * Parameter constructor for weighted graphs.
     * @param u - one airport the route is connected to
     * @param v - the other airport it is connected to
     * @param w - the weight of the route
     * @param lbl - the route label
     */
    Route(Airport u, Airport v, int w, std::string lbl)
        : source(u), dest(v), label(lbl), weight(w)
    { /* nothing */
    }

    /**
     * Default constructor.
     */
    Route() : source(""), dest(""), label(""), weight(-1)
    { /* nothing */
    }

    /**
     * Compares two Routes.
     * operator< is defined so Routes can be sorted with std::sort.
     * @param other - the route to compare with
     * @return whether the current route is less than the parameter
     */
    bool operator<(const Route& other) const
    {
        return weight < other.weight;
    }

    /**
     * Gets route label.
     */
    string getLabel() const
    {
        return this->label;
    }

    /**
     * Gets route weight.
     */
    int getWeight() const
    {
        return this->weight;
    }

    /**
     * Compares two routes' source and dest.
     * @param other - the route to compare with
     */
    bool operator==(Route& other) const
    {
        if (this->source.getID() != other.source.getID())
            return false;
        if (this->dest.getID() != other.dest.getID())
            return false;
        return true;
    }
private:
    std::string label; /**< The route label **/
    int weight; /**< The route weight (if in a weighed graph) **/

};
