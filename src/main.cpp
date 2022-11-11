#include "graph.h"

int main(){
    std::string airportFile = "airports.dat";
    std::string routesFile = "routes.dat";
    Graph g(airportFile, routesFile);
    return 0;
}