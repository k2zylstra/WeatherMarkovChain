//
// Created by kieran on 12/20/18.
//

#ifndef WEATHERMARKOVCHAIN_WEATHERGRAPH_H
#define WEATHERMARKOVCHAIN_WEATHERGRAPH_H

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

enum weatherType {

    rain,
    clouds,
    thunder,
    sun,
    snow,
    partly_cloudy,
    other
};

struct weatherNode;

struct edge {

    double weight;
    int timesOccured;
    weatherNode *childNode;
    weatherNode *parentNode;

    void calcWeight() {

        weight = 1 / ( 1+ exp(timesOccured));
    }

    edge() {
        timesOccured = 0;
        weight = 0;
    }
};

struct weatherNode {

    string strType;
    weatherType type;
    vector<edge*> paths;

    weatherNode() {
        strType = "";
    }
};

class WeatherGraph {

public:
    WeatherGraph();
    void addNode(weatherNode *wN);
    bool contains(weatherType wt, string strType);

private:
    void addEdge(weatherNode *start, weatherNode *end);
    vector<weatherNode*> adjList;
};


#endif //WEATHERMARKOVCHAIN_WEATHERGRAPH_H
