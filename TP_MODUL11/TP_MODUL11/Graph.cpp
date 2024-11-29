//
//  Graph.cpp
//  TP_MODUL11
//
//  Created by Falah Razan Hibrizi on 24/11/24.
//

#include "Graph.h"

void createVertex_103012300245(char newVertexID, adrVertex &v) {
    v = new Vertex;
    infoVertex(v) = newVertexID;
    nextVertex(v) = nullptr;
    firstEdge(v) = nullptr;
}

void initGraph_103012300245(Graph &G) {
    start(G) = nullptr;
}

void addVertex_103012300245(Graph &G, char newVertexID) {
    adrVertex newVertex;
    createVertex_103012300245(newVertexID, newVertex);

    if (start(G) == nullptr) {
        start(G) = newVertex;
    } else {
        adrVertex temp = start(G);
        while (nextVertex(temp) != nullptr) {
            temp = nextVertex(temp);
        }
        nextVertex(temp) = newVertex;
    }
}

void buildGraph_103012300245(Graph &G) {
    char newVertexID;
    cout << "Masukkan ID vertex (A-Z, atau karakter non-huruf untuk berhenti): ";
    cin >> newVertexID;

    while ((newVertexID >= 'A' && newVertexID <= 'Z') || (newVertexID >= 'a' && newVertexID <= 'z')) {
        addVertex_103012300245(G, newVertexID);
        cout << "Masukkan ID vertex (A-Z, atau karakter non-huruf untuk berhenti): ";
        cin >> newVertexID;
    }
}


