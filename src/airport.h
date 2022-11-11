# pragma once

# include <vector>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>

using namespace std;
class Airport {
    public:
        Airport();
        Airport(int id, std::string name, std::string city, std::string country, double latitude, double longitude);
        Airport(std::string airport);

        int getID();
        std::string getName();
        std::string getCity();
        std::string getCountry();
        double getLatitude();
        double getLongitude();

    private:
        int id_;
        std::string name_;
        std::string city_;
        std::string country_;
        double latitude_;
        double longitude_;
};
