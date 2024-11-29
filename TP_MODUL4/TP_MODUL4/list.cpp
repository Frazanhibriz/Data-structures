//
//  list.cpp
//  TP_MODUL4
//
//  Created by Falah Razan Hibrizi on 06/10/24.
//

#include <iostream>
#include "list.h"

using namespace std;

void createList(List &L) {
    first(L) = NULL;
}

address allocate(infotype x) {
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;

    return p;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List &L, address P) {
    if (first(L) == NULL) {
        // Jika list kosong, masukkan elemen di awal
        first(L) = P;
    } else {
        // Jika tidak kosong, tambahkan di akhir
        address Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfter(List &L, address prec, address P) {
    if (prec != NULL) {
        // Menyisipkan elemen baru setelah elemen dengan address prec
        next(P) = next(prec);
        next(prec) = P;
    }
}

void printInfo(List L) {
    address p = first(L);

    while (p != NULL) {
        cout << info(p) << " ";
        p = next(p);
    }

    cout << endl;
}
