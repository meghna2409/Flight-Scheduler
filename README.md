# flight-scheduler
Team Members: Meghna, Lysa, Anna

Presentation Video: https://youtu.be/BoUfP1WeuDc

Presentation Slides: https://docs.google.com/presentation/d/1M_Xi1b1_7m6F_GsSpbC5NF6ERCjD9DdajQCsibCGojU/edit?usp=sharing

## Overview
The objective of this project is to analyze common flight routes and the evolution of these routes in the past eight years. To accomplish this we will be using the [OpenFlights dataset](https://openflights.org/data.html), which has access to flight routes and airports dated from 2014. We used the information from the dataset to compute the distance and find the shortest path between any two cities by using DFS and Dijkstra's algorithm. We also used the PageRank method to locate the most significant airports and map them.

## Dijkstra's
#### Files: dijkstra.h/cpp
Dijkstra's algorithm is used to determine the distance between relative nodes by selecting and starting and ending point and using the latitude and longitude coordinates to calculate the distance between them. This algorithm returns a vector of vertices representing the shortest path between any two airports. The complexity for time would be O((|V| + |E|) log V), and for space, it would be O(|V| + |E|).

## Pagerank
#### Files: pagerank.h/cpp
The PageRank algorithm is used to locate the msot significant airports and map them. The input is an adjacency list representing the directed graph, and the algorithm returns a vector where each value denotes the importance of each airport. The complexity for time would be O(k(V+E)), and for space, it would be O(V).

## Flights
#### Files: flights.h/cpp
Flight uses Graph and Parse to create a working mapping of airplanes and their routes by storing the distance of each route acquired from Parse, keeping track of a map between airport IDs and their location which is also from Parse, and constructing a directed graph resulting from the parsed airport data.

## Graph
#### Files: graph.h/cpp
The Graph class represents a graph where airports are vertices and edges from an airport to another exists if there is a route from the two airports.

## Parse
#### Files: parse.h/cpp
Parse parses the routes data by line, determines the departure and arrival airport of each routes and stores them into a vector of Routes. Parse parses the airport data and determines the ID, latitude and longitude of each airport and creates a mapping from the ID of the airport to their location. Route also has methods to find the distances between two locations or find the distances of all the routes in the vector of stored Routes which is stored in a mapping and publicly accessible.

## Installation Instructions
Run Tests
```
make tests
./tests
```

Run Main
```
make final
./final
```
