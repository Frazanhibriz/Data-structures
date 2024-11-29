//
//  Graph.h
//  TP_MODUL11
//
//  Created by Falah Razan Hibrizi on 24/11/24.
//

#ifndef GRAPH_H
#define GRAPH_H
#define start(G) G.firstVertex
#define nextVertex(P) P->nextVertex
#define firstEdge(P) P->firstEdge
#define infoVertex(P) P->idVertex
#define nextEdge(P) P->nextEdge
#define destVertexID(P) P->destVertexID
#define edgeWeight(P) P->weight

#include <iostream>
using namespace std;

struct Edge;
struct Vertex;

typedef Vertex* adrVertex;
typedef Edge* adrEdge;

struct Vertex {
    char idVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct Edge {
    char destVertexID;
    int weight;
    adrEdge nextEdge;
};

struct Graph {
    adrVertex firstVertex;
};

void createVertex_103012300245(char newVertexID, adrVertex &v);
void initGraph_103012300245(Graph &G);
void addVertex_103012300245(Graph &G, char newVertexID);
void buildGraph_103012300245(Graph &G);

#endif

