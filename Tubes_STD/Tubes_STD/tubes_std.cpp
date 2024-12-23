//
//  tubes_std.cpp
//  Tubes_STD
//
//  Created by Falah Razan Hibrizi on 01/12/24.
//

#include "tubes_std.h"

void createList_ecommerce(List_ecommerce &Le) {
    first(Le) = NULL;
}

adr_ecommerce create_elemen_ecommerce(ecommerce xe) {
    adr_ecommerce pe = new elemen_ecommerce;
    info(pe) = xe;
    next_ecommerce(pe) = NULL;
    next_toko_online(pe) = NULL;
    return pe;
}

void insert_first_ecommerce(List_ecommerce &Le, adr_ecommerce pe) {
    if (first(Le) == NULL) {
        first(Le) = pe;
    } else {
        next_ecommerce(pe) = first(Le);
        first(Le) = pe;
    }
}

void delete_last_ecommerce(List_ecommerce &Le, adr_ecommerce &pe) {
    if (first(Le) == NULL) {
        pe = NULL;
    } else if (next_ecommerce(first(Le)) == NULL) {
        pe = first(Le);
        first(Le) = NULL;
    } else {
        adr_ecommerce q = first(Le);
        while (next_ecommerce(next_ecommerce(q)) != NULL) {
            q = next_ecommerce(q);
        }
        pe = next_ecommerce(q);
        next_ecommerce(q) = NULL;
    }
}

void showlist_ecommerce(List_ecommerce Le) {
    adr_ecommerce pe = first(Le);
    while (pe != NULL) {
        cout << "ID E-commerce: " << info(pe).id_ecommerce << endl;
        cout << "Nama E-commerce: " << info(pe).nama_ecommerce << endl;
        cout << "Jumlah User: " << info(pe).jumlah_user << endl;
        cout << "Jumlah Toko: " << info(pe).jumlah_toko << endl;
        cout << "Biaya Layanan: " << info(pe).biaya_layanan << endl;
        showlist_toko_online(pe);
        cout << "--------------------------" << endl;
        pe = next_ecommerce(pe);
    }
}

void createList_toko_online(List_toko_online &Lt) {
    Lt.First = NULL;
}

adr_toko_online create_elemen_toko_online(toko_online xt) {
    adr_toko_online pt = new elemen_toko_online;
    info(pt) = xt;
    next_toko_online(pt) = NULL;
    return pt;
}


void insert_last_toko_online(adr_toko_online &head, adr_toko_online pt) {
    if (head == NULL) {
        head = pt;
    } else {
        adr_toko_online q = head;
        while (next_toko_online(q) != NULL) {
            q = next_toko_online(q);
        }
        next_toko_online(q) = pt;
    }
}



void delete_first_toko_online(adr_toko_online &head, adr_toko_online &pt) {
    if (head == NULL) {
        pt = NULL;
    } else {
        pt = head;
        head = next_toko_online(head);
        next_toko_online(pt) = NULL;
    }
}

void showlist_toko_online(adr_ecommerce pe) {
    adr_toko_online pt = next_toko_online(pe);
    while (pt != NULL) {
        cout << "  - ID Toko: " << info(pt).id_toko << endl;
        cout << "  - Nama Toko: " << info(pt).nama_toko << endl;
        cout << "  - Pemilik Toko: " << info(pt).pemilik_toko << endl;
        cout << "  - Total Produk: " << info(pt).total_product << endl;
        cout << "  - Lokasi: " << info(pt).lokasi << endl;
        pt = next_toko_online(pt);
    }
}


adr_ecommerce search_ecommerce(List_ecommerce Le, string id_ecommerce) {
    adr_ecommerce pe = first(Le);
    while (pe != NULL) {
        if (info(pe).id_ecommerce == id_ecommerce) {
            return pe;
        }
        pe = next_ecommerce(pe);
    }
    return NULL;
}
