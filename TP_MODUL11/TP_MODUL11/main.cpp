//
//  main.cpp
//  TP_MODUL11
//
//  Created by Falah Razan Hibrizi on 24/11/24.
//

#include "Graph.h"

#define ID(v) (v->idVertex)
#define NEXT(v) (v->nextVertex)

int main() {
    Graph G;
    initGraph_103012300245(G);

    cout << "Proses membangun graph:\n";
    buildGraph_103012300245(G);

    // Menampilkan hasil
    cout << "\nHasil graph:\n";
    adrVertex v = G.firstVertex;
    while (v != nullptr) {
        cout << ID(v) << " -> ";  
        v = NEXT(v);
    }
    cout << "null\n";

    return 0;
}
