# include "airport.h"

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

Airport::Airport(std::string airport) {
    vector<string> result;
    stringstream s_stream(airport);
    while(s_stream.good()) {
        string substr;
        getline(s_stream, substr, ','); //get first string delimited by comma
        result.push_back(substr);
    }
    if (result.size == 6 && result[0] != -1) {
        // change constructor
        Airport airport(result[0], result[1], result[2],);
        addVertex(airport.getID(), airport);
    }
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

std::string Airport::getCity() {
    return city_;
}   

std::string Airport::getCountry() {
    return country_;
}

double Airport::getLatitude() {
    return latitude_;
}

double Airport::getLongitude() {
    return longitude_;
}