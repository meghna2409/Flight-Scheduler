#pragma once

#include "airport.h"

#include <string>
#include <limits.h>

class Route
{
  public:
    int sourceID; /**< The source of the route **/
    int destID; /**< The destination of the route **/

    /**
     * Parameter constructor for weighted graphs.
     * @param u - one airport the route is connected to
     * @param v - the other airport it is connected to
     * @param w - the weight of the route
     * @param lbl - the route label
     */
    Route(int u, int v, int w, std::string lbl)
        : sourceID(u), destID(v), label(lbl), weight(w)
    { /* nothing */
    }

    /**
     * Default constructor.
     */
    Route() : sourceID(-1), destID(-1), label(""), weight(-1)
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
        if (this->sourceID != other.sourceID)
            return false;
        if (this->destID != other.destID)
            return false;
        return true;
    }
private:
    std::string label; /**< The route label **/
    int weight; /**< The route weight (if in a weighed graph) **/

};
