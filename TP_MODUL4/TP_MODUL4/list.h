//
//  list.h
//  TP_MODUL4
//
//  Created by Falah Razan Hibrizi on 06/10/24.
//

#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);

address allocate(infotype x);

void insertFirst(List &L, address P);

void insertAfter(List &L, address prec, address P);

void insertLast(List &L, address P);

void printInfo(List L);
