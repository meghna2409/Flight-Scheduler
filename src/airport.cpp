# include "Airport.h"

// Default constructor
Airport::Airport() {
    id_ = 0;
    name_ = "";
    city_ = "";
    country_ = "";
    latitude_ = 0.0;
    longitude_ = 0.0;
}

// Constructor
Airport::Airport(int id, std::string name, std::string city, std::string country, double latitude, double longitude) {
    id_ = id;
    name_ = name;
    city_ = city;
    country_ = country;
    latitude_ = latitude;
    longitude_ = longitude;
}

int Airport::getID() {
    return id_;
}

std::string Airport::getName() {
    return name_;
}

std::string getCity() {
    return city_;
}   

std::string getCountry() {
    return country_;
}

double getLatitude() {
    return latitude_;
}

double getLongitude() {
    return longitude_;
}