//
//  flight.h
//  TP_MODUL_10
//
//  Created by Falah Razan Hibrizi on 17/11/24.
//

#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
using namespace std;

#define first(L) L.First
#define next(P) P->next
#define info(P) P->info

struct jadwalPenerbangan {
    string kode;
    string jenis;
    string tanggal;
    string waktu;
    string asal;
    string tujuan;
    int kapasitas;
};

typedef jadwalPenerbangan infotype;
typedef struct elemenJadwal* adr_jadwalIP;

struct elemenJadwal {
    infotype info;
    adr_jadwalIP next;
};

struct ListJadwal {
    adr_jadwalIP First;
};

void createListJadwal_103012300245(ListJadwal &L);
adr_jadwalIP createElemenJadwal_103012300245(infotype x);
void insertLastJ_103012300245(ListJadwal &L, adr_jadwalIP P);
void showJadwal_103012300245(ListJadwal L);
void deleteFirstJ_103012300245(ListJadwal &L, adr_jadwalIP &P);
bool searchJ_103012300245(ListJadwal L, string dari, string ke, string tanggal);

#endif
