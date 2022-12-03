#pragma once

#include <vector>
using namespace std;

class PageRank {
  public:
    void adjacency(int num1, double num2);
    vector<double> pr(vector<double> start, int time, bool status);
    vector<int> pick_airport(int num);
    vector<double> vec();
    vector<vector<double>> adjacency_vector; 
    vector<int> list; 
    vector<double> result; 
    int num;
};