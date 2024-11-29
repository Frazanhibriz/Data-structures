//
//  DLL.h
//  TP_MODUL6
//
//  Created by Falah Razan Hibrizi on 21/10/24.
//

#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <string>

using namespace std;


struct bandLagu {
    string judulLagu;
    string penulis;
};


typedef bandLagu infotype;
typedef struct elmtList *address;

struct elmtList {
    infotype info;
    address prev;
    address next;
};

struct list {
    address first;
    address last;
};


#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev


bool isEmpty(list L);


void createList(list &L);


void createNewElmt(infotype X, address &P);


void insertFirst(list &L, address P);


void insertAfter(list &L, address Prec, address P);


void insertLast(list &L, address P);


void deleteFirst(list &L, address &P);


void deleteAfter(list &L, address Prec, address &P);


void deleteLast(list &L, address &P);


void concat(list L1, list L2, list &L3);


address findLagu(string Judul, list L);


void removeLagu(string Judul, list &L);

#endif
