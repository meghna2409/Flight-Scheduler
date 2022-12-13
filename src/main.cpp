#include <iostream>
#include "flights.h"
#include "parse.h"
#include "dijkstra.h"
#include "edge.h"
#include <vector>
using namespace std;

int main() {
    Parse p;
    p.parseRoutes("data/airports.dat.csv", "data/routes.dat.csv");
    Flights* f = new Flights();
    Dijkstra d;

    std::string userSource;
    std::string userDestination;

    std::cout<< "\nHello! Let's find the shortest flight! \n" <<endl;
    int counter = 0;
    bool proper_response = false;
   //will repeat until proper responses were given
    while (!proper_response) {
       //storing user input into user variables
        std::cout<< "Enter the departure airport ID." << endl;
        std::cin >> userSource;
        transform(userSource.begin(), userSource.end(), userSource.begin(),
                ::toupper);
        std::cout<< "Enter the arrival airport ID." << endl;
        std::cin >> userDestination;
        transform(userDestination.begin(), userDestination.end(), userDestination.begin(),
                ::toupper);

        //if true, then create graph
        proper_response = p.isValid(userSource, userDestination);
        if (proper_response) {
            std::cout <<"\n" <<std::endl;
            std::cout << "Calculating route... \n" <<std::endl;
            f->storeAirportData(userSource, userDestination);
            Airport s(userSource);
            Airport z(userDestination);
            vector<string> path = d.dijkstra(f->graph, s, z);
            path.push_back(userSource);
    
            std::reverse(path.begin(), path.end());
            for (size_t i = 0; i < path.size(); i++) {
                std::cout << path[i] << std::endl;
                if (i != path.size() - 1) {
                    std::cout << " -> " << std::endl;
                }
            }
        }   else if (!proper_response) {
            counter++;
            std::cout<< "You did not put in valid responses. \n \n" << endl;
            if (counter > 3) {
                std::cout<< "Rerun Program." << endl;
                exit(1);
            }
        }
    }
}