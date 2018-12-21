//
// Created by kieran on 12/20/18.
//

#include "WeatherGraph.h"

WeatherGraph::WeatherGraph() {

    auto *sunNode = new weatherNode();
    sunNode->type = sun;
    auto *rainNode = new weatherNode();
    rainNode->type = rain;
    auto *thunderNode = new weatherNode();
    rainNode->type = thunder;
    auto *cloudNode = new weatherNode();
    cloudNode->type = clouds;
    auto *snowNode = new weatherNode();
    snowNode->type = snow;
    auto *partlyCloudyNode = new weatherNode();
    partlyCloudyNode->type = partly_cloudy;

    addNode(sunNode);
    addNode(rainNode);
    addNode(thunderNode);
    addNode(cloudNode);
    addNode(snowNode);
    addNode(partlyCloudyNode);
}

void WeatherGraph::addNode(weatherNode *wN) {

    if (!contains(wN->type, wN->strType)) {

        adjList.push_back(wN);

        for (int i = 0; i < adjList.size(); i++) {

            addEdge(wN, adjList[i]);
        }

        for (int i = 0; i < adjList.size(); i++) {

            addEdge(adjList[i], wN);
        }
    }
}

void WeatherGraph::addEdge(weatherNode *start, weatherNode *end) {

    edge *toAdd = new edge();
    toAdd->parentNode = end;
    toAdd->childNode = start;

    start->paths.push_back(toAdd);
}

bool WeatherGraph::contains(weatherType wt, string strType) {

    bool toReturn = false;

    for (int i = 0; i < adjList.size(); i++) {

        if (adjList[i]->type == wt) {

            toReturn = true;
        }
        else if (adjList[i]->type == other) {

            if (adjList[i]->strType == strType) {

                toReturn = true;
            }
        }
    }

    return toReturn;
}