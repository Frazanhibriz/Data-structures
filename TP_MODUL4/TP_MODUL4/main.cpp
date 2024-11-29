//
//  main.cpp
//  TP_MODUL4
//
//  Created by Falah Razan Hibrizi on 06/10/24.
//

#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List L;
    int angka;
    address P;

    createList(L);

    cout << "Masukan angka pertama dari 3 digit terakhir NIM anda: ";
    cin >> angka;

    P = allocate(angka);
    insertFirst(L, P);
    printInfo(L);
    
    cout << "Masukan angka kedua dari 3 digit terakhir NIM anda: ";
    cin >> angka;

    P = allocate(angka);
    insertFirst(L, P);
    printInfo(L);
    
    cout << "Masukan angka ketiga dari 3 digit terakhir NIM anda: ";
    cin >> angka;

    P = allocate(angka);
    insertFirst(L, P);
    printInfo(L);
    
    cout << "Masukan digit untuk elemen terakhir: ";
    cin >> angka;
    
    P = allocate(angka);
    insertLast(L, P);
    printInfo(L);

    return 0;
}
