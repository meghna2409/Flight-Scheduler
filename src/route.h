#pragma once

#include "Airport.h"

#include <string>
#include <limits.h>

using namespace std;
class Route {
  public:
    /**
     * Parameter constructor for weighted graphs.
     * @param u - one airport the route is connected to
     * @param v - the other airport it is connected to
     * @param w - the weight of the route
     * @param lbl - the route label
     */
    Route(int u, int v, int w, std::string lbl);
    /**
     * Default constructor.
     */
    Route();

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
    std::string getLabel() const
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

    int getSourceID() const {
        return sourceID;
    }

    int getDestID() const {
        return destID;
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
    int sourceID; /**< The source of the route **/
    int destID; /**< The destination of the route **/

};