//
//  tubes_std.h
//  Tubes_STD
//
//  Created by Falah Razan Hibrizi on 01/12/24.
//

#include <iostream>

using namespace std;

#define first(L) (L).First
#define next_ecommerce(P) (P)->next_ecommerce
#define next_toko_online(P) (P)->next_toko_online
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
    adr_toko_online next_toko_online;
};

struct elemen_toko_online {
    toko_online info;
    adr_toko_online next_toko_online;
};

struct List_ecommerce {
    adr_ecommerce First;
};

struct List_toko_online {
    adr_toko_online First;
};


void createList_ecommerce(List_ecommerce &Le);
adr_ecommerce create_elemen_ecommerce(ecommerce xe);
void insert_first_ecommerce(List_ecommerce &Le, adr_ecommerce pe);
void delete_last_ecommerce(List_ecommerce &Le, adr_ecommerce &pe);
adr_ecommerce search_ecommerce(List_ecommerce Le, string id_ecommerce);
void showlist_ecommerce(List_ecommerce Le);

void createList_toko_online(List_toko_online &Lt);
adr_toko_online create_elemen_toko_online(toko_online xt);
void insert_last_toko_online(adr_toko_online &head, adr_toko_online pt);
void delete_first_toko_online(adr_toko_online &head, adr_toko_online &pt);
void showlist_toko_online(adr_ecommerce pe);


