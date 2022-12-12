# cs225_finalproject
Group Members: Meghna, Lysa, Anna

## Overview
The objective of this project is to analyze common flight routes and the evolution of these routes in the past eight years. To accomplish this we will be usin the OpenFlights dataset, which has access to flight routes and airports dated from 2014. We used the information from the dataset to compute the distance and find the shortest path between any two cities by using DGS and Dijkstra's algorithm. We also used the PageRank method to locate the most significant airports and map them.

## Dijkstra's
#### Files: dijkstra.h/cpp
Dijkstra's algorithm is used to determine the distance between relative nodes by selecting and starting and ending point and using the latitude and longitude coordinates to calculate the distance between them. This algorithm returns a vector of vertices representing the shortest path between any two airports. The complexity for time would be O((|V| + |E|) log V), and for space, it would be O(|V| + |E|).

## Pagerank
#### Files: pagerank.h/cpp
The PageRank algorithm is used to locate the msot significant airports and map them. The input is an adjacency list representing the directed graph, and the algorithm returns a vector where each value denotes the importance of each airport. The complexity for time would be O(k(V+E)), and for space, it would be O(V).

## Graph
#### Files: graph.h/cpp

## Parse
#### Files: parse.h/cpp

## Flights
#### Files: flights.h/cpp

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
