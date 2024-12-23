#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
using namespace std;


#define first(L) (L).First
#define first_toko_online(P) (P)->first_toko_online
#define next_ecommerce(P) (P)->next_ecommerce
#define next_toko_online(P) (P)->next_toko_online
#define prev_toko_online(P) (P)->prev_toko_online
#define info(P) (P)->info


struct ecommerce {
    string id_ecommerce;
    string nama_ecommerce;
    int jumlah_user;
    int jumlah_toko;
    int biaya_layanan;
};

struct toko_online {
    string id_toko;
    string nama_toko;
    string pemilik_toko;
    int total_product;
    string lokasi;
};


typedef struct elemen_ecommerce *adr_ecommerce;
typedef struct elemen_toko_online *adr_toko_online;


struct elemen_ecommerce {
    ecommerce info;
    adr_ecommerce next_ecommerce;
    adr_toko_online first_toko_online;
};

struct elemen_toko_online {
    toko_online info;
    adr_toko_online next_toko_online;
    adr_toko_online prev_toko_online;
};

struct List_ecommerce {
    adr_ecommerce First;
};

void createList_ecommerce(List_ecommerce &Le);
void showlist_ecommerce(List_ecommerce Le);
void showList_toko_online(adr_ecommerce pe);

adr_ecommerce create_elemen_ecommerce(ecommerce xe);
adr_toko_online create_elemen_toko_online(toko_online xt);

void insert_first_ecommerce(List_ecommerce &Le, adr_ecommerce pe);
void insert_last_ecommerce(List_ecommerce &Le, adr_ecommerce pe);
void insert_after_ecommerce(adr_ecommerce prec, adr_ecommerce pe);

void insert_first_toko_online(adr_ecommerce pe, adr_toko_online pt);
void insert_last_toko_online(adr_ecommerce pe, adr_toko_online pt);
void insert_after_toko_online(adr_toko_online prec, adr_toko_online pt);

adr_ecommerce search_ecommerce(List_ecommerce Le, string id_ecommerce);

void delete_first_ecommerce(List_ecommerce &Le, adr_ecommerce &pe);
void delete_last_ecommerce(List_ecommerce &Le, adr_ecommerce &pe);
void delete_after_ecommerce(adr_ecommerce prec, adr_ecommerce &pe);

void delete_first_toko_online(adr_ecommerce pe, adr_toko_online &pt);
void delete_last_toko_online(adr_ecommerce pe, adr_toko_online &pt);
void delete_after_toko_online(adr_toko_online prec, adr_toko_online &pt);

bool is_ecommerce_exist(List_ecommerce Le, string id_ecommerce);
bool is_toko_exist(adr_toko_online head, string id_toko);

bool insert_ecommerce_safe(List_ecommerce &Le, ecommerce xe);
bool insert_toko_online_safe(adr_ecommerce pe, toko_online xt);

void update_jumlah_toko(adr_ecommerce pe);

void showAllData(List_ecommerce Le);

int countEcommerce(List_ecommerce Le);



#endif
