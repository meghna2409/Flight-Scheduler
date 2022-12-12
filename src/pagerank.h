#pragma once

#include <vector>
using namespace std;

class PageRank {
  public:
    // Makes adjustments to the adjacency matrix.
    void adjacency(int num1, double num2);

    // Completes the pagerank algorithm.
    vector<double> pr(vector<double> start, int time, bool status);

    // Returns the most important airports.
    vector<int> pick_airport(int num);

    // Returns the starting vector to complete pagerank.
    vector<double> vec();

    // Adjacency matrix.
    vector<vector<double>> adjacency_vector; 

    // Airport name list with ID.
    vector<int> list; 

    // Output of the pagerank algorithm.
    vector<double> result; 

    // Dimensions of the starting vector, adjacency matrix, list, and the result vector
    int num;
};