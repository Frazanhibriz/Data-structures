//
//  DLL.cpp
//  TP_MODUL6
//
//  Created by Falah Razan Hibrizi on 21/10/24.
//

#include "DLL.h"


bool isEmpty(list L) {
    return (first(L) == NULL);
}


void createList(list &L) {
    first(L) = NULL;
    last(L) = NULL;
}


void createNewElmt(infotype X, address &P) {
    P = new elmtList;
    if (P != NULL) {
        info(P) = X;
        prev(P) = NULL;
        next(P) = NULL;
    }
}


void insertFirst(list &L, address P) {
    if (isEmpty(L)) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}


void insertAfter(list &L, address Prec, address P) {
    if (Prec != NULL) {
        next(P) = next(Prec);
        if (next(Prec) != NULL) {
            prev(next(Prec)) = P;
        }
        next(Prec) = P;
        prev(P) = Prec;
        
        if (next(P) == NULL) {
            last(L) = P;
        }
    }
}


void insertLast(list &L, address P) {
    if (isEmpty(L)) {
        first(L) = P;
        last(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}


void deleteFirst(list &L, address &P) {
    if (!isEmpty(L)) {
        P = first(L);
        if (next(first(L)) == NULL) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(first(L));
            prev(first(L)) = NULL;
        }
    }
}


void deleteAfter(list &L, address Prec, address &P) {
    if (Prec != NULL && next(Prec) != NULL) {
        P = next(Prec);
        next(Prec) = next(P);
        if (next(P) != NULL) {
            prev(next(P)) = Prec;
        } else {
            last(L) = Prec;
        }
    }
}


void deleteLast(list &L, address &P) {
    if (!isEmpty(L)) {
        P = last(L);
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            last(L) = prev(last(L));
            next(last(L)) = NULL;
        }
    }
}


void concat(list L1, list L2, list &L3) {
    createList(L3);
    
    address P = first(L1);
    while (P != NULL) {
        address temp;
        createNewElmt(info(P), temp);
        insertLast(L3, temp);
        P = next(P);
    }
    
    P = first(L2);
    while (P != NULL) {
        address temp;
        createNewElmt(info(P), temp);
        insertLast(L3, temp);
        P = next(P);
    }
}


address findLagu(string Judul, list L) {
    address P = first(L);
    while (P != NULL) {
        if (info(P).judulLagu == Judul) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}


void removeLagu(string Judul, list &L) {
    address P = findLagu(Judul, L);
    if (P != NULL) {
        if (P == first(L)) {
            deleteFirst(L, P);
        } else if (P == last(L)) {
            deleteLast(L, P);
        } else {
            deleteAfter(L, prev(P), P);
        }
    }
}
