#include <iostream>
#include "pagerank.h"
#include <vector>
#include <numeric>
#include <math.h>

void PageRank::adjacency(int num1, double num2) {
    this->num = num1;
    double d = (1 - num2) / num;
    for (int i = 0; i < num; i++) {
        double sum = 0;
        for (int j = 0; j < num; j++){
            sum += adjacency_vector[j][i];
        }     
        for (int k = 0; k < num; k++) {
            if (sum == 0) {
                adjacency_vector[k][i] = 1 / (double)num;
            } else {
                adjacency_vector[k][i] = (adjacency_vector[k][i] / sum) * num2 + d;
            }
        }               
    }
}

vector<double> PageRank::pr(vector<double> start, int time, bool status) {
    vector<double> temp1 = start;
    vector<double> temp2 = start;
    for(int t = 0; t < time; t++){
        for(int i = 0; i < num; i++){
            temp2[i] = 0;
            for (int j = 0; j < num; j++) {
                temp2[i] += adjacency_vector[i][j] * temp1[j];
                if (status == true) {
                    double sum = 0;
                    for (std::vector<double>::iterator it = temp2.begin(); it != temp2.end(); it++) {
                        sum += (*it)*(*it);
                    }
                    double nm = sqrt(sum);
                    for (int n = 0; n < num; n++) {
                        temp2[n] = temp2[n] / nm;
                    }
                }
            }     
        }
        temp1 = temp2;
    }
    result = temp1;
    return temp1;
}

vector<int> PageRank::pick_airport(int num){
    vector<int> airport;
    vector<double> biggest;
    biggest.resize(num);
    airport.resize(num);
    int pos = 0;
    for (int i = 0; i < num; i++){
        double maximum = 0;
        for (auto it = result.begin(); it != result.end(); it++) {
            if (*it > maximum) {
                bool flag = true;
                for (auto temp = biggest.begin(); temp != biggest.end(); temp++) {
                    if (*temp == *it) {
                        flag = false;
                        break;
                    }
                }
                if (flag == true) maximum = *it;
            }
        }
        biggest[pos] = maximum;
        pos++;
    }

    pos = 0;
    for(int i = 0; i < num; i++){
        int count = 0;
        for(auto it = result.begin(); it != result.end(); ++it){
            if(biggest[i] == *it){
                airport[pos] = (list[count]);
                pos++;
            }
            count++;
        }
    }
    return airport;
}

vector<double> PageRank::vec() {
    vector<double> start;
    start.resize(this->num);
    for (int i = 0; i < this->num; i++){
        start[i] = rand();
    }
    return start;
}