# pragma once

# include <vector>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>

using namespace std;
class Airport {
    public:
        /**
         * Constructs an airport that initializes private members to 
         * default value.
         */
        Airport();

        /**
         * Constructs an airport with the given paramters.
         * 
         * @param id Unique OpenFlights identifier for this airport.
         * @param name Name of airport.
         * @param city Main city served by airport.
         * @param country Country or territory where airport is located.
         * @param latitude Decimal degrees, usually to six significant 
         * digits. Negative is South, positive is North.
         * @param lontitude Decimal degrees, usually to six significant 
         * digits. Negative is West, positive is East.
         */
        Airport(int id, std::string name, std::string city, std::string country, double latitude, double longitude);

        /**
         * Constructs an airport from a string that contains the basic
         * information of the airports.
         * 
         * @param airport the string to read from.
         */
        Airport(std::string airport);

        /**
         * Gets the id of the airport.
         * @return id of the airport.
         */
        int getID();

        /**
         * Gets the name of the airport.
         * @return name of the airport.
         */
        std::string getName();

        /**
         * Gets the city of the airport.
         * @return city of the airport.
         */
        std::string getCity();

        /**
         * Gets the country of the airport.
         * @return country of the airport.
         */
        std::string getCountry();

        /**
         * Gets the latitude of the airport.
         * @return latitude of the airport.
         */
        double getLatitude();

        /**
         * Gets the longitude of the airport.
         * @return longitude of the airport.
         */
        double getLongitude();

    private:
        int id_;                    /*< Id of the airport */
        std::string name_;          /*< Name of the airport */
        std::string city_;          /*< City of the airport */
        std::string country_;       /*< Country of the airport */
        double latitude_;           /*< Latitude of the airport. Negative is South, positive is North. */
        double longitude_;          /*< Longitude of the airport. Negative is West, positive is East. */
};
