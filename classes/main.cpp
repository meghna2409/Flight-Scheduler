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

    std::cout<< "\n Welcome! Let's find the shortest flight! \n" <<endl;
    int counter = 0;
    bool proper_response = false;
   //will repeat until proper responses were given
    while (!proper_response) {
       //storing user input into user variables
        std::cout<< "Enter the source IATA airport." << endl;
        std::cin >> userSource;
        transform(userSource.begin(), userSource.end(), userSource.begin(),
                ::toupper);
        std::cout<< "Enter the destination IATA airport." << endl;
        std::cin >> userDestination;
        transform(userDestination.begin(), userDestination.end(), userDestination.begin(),
                ::toupper);

        //if true, then create graph
        proper_response = p.isValid(userSource, userDestination);
        if (proper_response) {
            std::cout <<"\n" <<std::endl;
            std::cout << "Calculating route... \n" <<std::endl;
            std::cout << "Currently ensuring you have the best travel experience because YOU deserve it! \n" <<std::endl;

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
            

            std::cout << "Please refer to shortest_path.png for a visual representation of your upcoming flight. \n" <<std::endl;

            std::cout<< "Your starting airport is the green marker. Your ending point is the" 
             << " red marker. All stops are the yellow marker(s). \n" << std::endl;


            std::cout << "Thank you for using our Shortest Flight Booker.\n" << std::endl;
            //if the responses aren't right, then prompt user questions again
        }   else if (!proper_response) {
            counter++;
            std::cout<< "You did not put in valid responses. Make sure you are entering a valid IATA. \n \n" << endl;
            //if they do it wrong more than 3 times, then quits the program.
            if (counter > 3) {
                std::cout<< "Rerun Program." << endl;
                exit(1);
            }
        }
    }
}