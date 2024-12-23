#include "test.h"

void createList_ecommerce(List_ecommerce &Le) {
    first(Le) = NULL;
}


adr_ecommerce create_elemen_ecommerce(ecommerce xe) {
    adr_ecommerce pe = new elemen_ecommerce;
    info(pe) = xe;
    next_ecommerce(pe) = NULL;
    first_toko_online(pe) = NULL;
    return pe;
}


adr_toko_online create_elemen_toko_online(toko_online xt) {
    adr_toko_online pt = new elemen_toko_online;
    info(pt) = xt;
    next_toko_online(pt) = NULL;
    prev_toko_online(pt) = NULL;
    return pt;
}


void insert_first_ecommerce(List_ecommerce &Le, adr_ecommerce pe) {
    if (first(Le) == NULL) {
        first(Le) = pe;
    } else {
        next_ecommerce(pe) = first(Le);
        first(Le) = pe;
    }
}


void insert_last_ecommerce(List_ecommerce &Le, adr_ecommerce pe) {
    if (first(Le) == NULL) {
        first(Le) = pe;
    } else {
        adr_ecommerce temp = first(Le);
        while (next_ecommerce(temp) != NULL) {
            temp = next_ecommerce(temp);
        }
        next_ecommerce(temp) = pe;
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


void showlist_ecommerce(List_ecommerce Le) {
    adr_ecommerce pe = first(Le);
    while (pe != NULL) {
        cout << "ID E-commerce: " << info(pe).id_ecommerce << endl;
        cout << "Nama E-commerce: " << info(pe).nama_ecommerce << endl;
        cout << "Jumlah User: " << info(pe).jumlah_user << endl;
        cout << "Jumlah Toko: " << info(pe).jumlah_toko << endl;
        cout << "Biaya Layanan: " << info(pe).biaya_layanan << endl;
        cout << "--------------------------" << endl;
        pe = next_ecommerce(pe);
    }
}


void insert_first_toko_online(adr_ecommerce pe, adr_toko_online pt) {
    if (pe == NULL) return;
    if (first_toko_online(pe) == NULL) {
        first_toko_online(pe) = pt;
    } else {
        next_toko_online(pt) = first_toko_online(pe);
        prev_toko_online(first_toko_online(pe)) = pt;
        first_toko_online(pe) = pt;
    }
}


void delete_last_toko_online(adr_ecommerce pe, adr_toko_online &pt) {
    if (pe == NULL || first_toko_online(pe) == NULL) {
        pt = NULL;
    } else if (next_toko_online(first_toko_online(pe)) == NULL) {
        pt = first_toko_online(pe);
        first_toko_online(pe) = NULL;
    } else {
        adr_toko_online temp = first_toko_online(pe);
        while (next_toko_online(temp) != NULL) {
            temp = next_toko_online(temp);
        }
        pt = temp;
        prev_toko_online(pt)->next_toko_online = NULL;
        prev_toko_online(pt) = NULL;
    }
}


void insert_last_toko_online(adr_ecommerce pe, adr_toko_online pt) {
    if (pe == NULL) return;
    if (first_toko_online(pe) == NULL) {
        first_toko_online(pe) = pt;
    } else {
        adr_toko_online temp = first_toko_online(pe);
        while (next_toko_online(temp) != NULL) {
            temp = next_toko_online(temp);
        }
        next_toko_online(temp) = pt;
        prev_toko_online(pt) = temp;
    }
}


void delete_first_ecommerce(List_ecommerce &Le, adr_ecommerce &pe) {
    if (first(Le) == NULL) {
        pe = NULL;
    } else {
        pe = first(Le);
        first(Le) = next_ecommerce(pe);
        next_ecommerce(pe) = NULL;
    }
}


void delete_last_ecommerce(List_ecommerce &Le, adr_ecommerce &pe) {
    if (first(Le) == NULL) {
        pe = NULL;
    } else if (next_ecommerce(first(Le)) == NULL) {
        pe = first(Le);
        first(Le) = NULL;
    } else {
        adr_ecommerce temp = first(Le);
        while (next_ecommerce(next_ecommerce(temp)) != NULL) {
            temp = next_ecommerce(temp);
        }
        pe = next_ecommerce(temp);
        next_ecommerce(temp) = NULL;
    }
}

void delete_first_toko_online(adr_ecommerce pe, adr_toko_online &pt) {
    if (pe == NULL || first_toko_online(pe) == NULL) {
        pt = NULL;
    } else {
        pt = first_toko_online(pe);
        first_toko_online(pe) = next_toko_online(pt);
        if (first_toko_online(pe) != NULL) {
            prev_toko_online(first_toko_online(pe)) = NULL;
        }
        next_toko_online(pt) = NULL;
    }
}

void insert_after_ecommerce(adr_ecommerce prec, adr_ecommerce pe) {
    if (prec != NULL) {
        next_ecommerce(pe) = next_ecommerce(prec);
        next_ecommerce(prec) = pe;
    }
}

void insert_after_toko_online(adr_toko_online prec, adr_toko_online pt) {
    if (prec != NULL) {
        next_toko_online(pt) = next_toko_online(prec);
        if (next_toko_online(prec) != NULL) {
            prev_toko_online(next_toko_online(prec)) = pt;
        }
        next_toko_online(prec) = pt;
        prev_toko_online(pt) = prec;
    }
}

void delete_after_ecommerce(adr_ecommerce prec, adr_ecommerce &pe) {
    if (prec != NULL && next_ecommerce(prec) != NULL) {
        pe = next_ecommerce(prec);
        next_ecommerce(prec) = next_ecommerce(pe);
        next_ecommerce(pe) = NULL;
    }
}

void delete_after_toko_online(adr_toko_online prec, adr_toko_online &pt) {
    if (prec != NULL && next_toko_online(prec) != NULL) {
        pt = next_toko_online(prec);
        next_toko_online(prec) = next_toko_online(pt);
        if (next_toko_online(pt) != NULL) {
            prev_toko_online(next_toko_online(pt)) = prec;
        }
        next_toko_online(pt) = NULL;
        prev_toko_online(pt) = NULL;
    }
}

void update_jumlah_toko(adr_ecommerce pe) {
    if (pe == NULL) return;

    int count = 0;
    adr_toko_online pt = first_toko_online(pe);

    while (pt != NULL) {
        count++;
        pt = next_toko_online(pt);
    }

    info(pe).jumlah_toko = count;
}

bool is_ecommerce_exist(List_ecommerce Le, string id_ecommerce) {
    return search_ecommerce(Le, id_ecommerce) != NULL;
}

bool is_toko_exist(adr_toko_online head, string id_toko) {
    adr_toko_online pt = head;
    while (pt != NULL) {
        if (info(pt).id_toko == id_toko) {
            return true;
        }
        pt = next_toko_online(pt);
    }
    return false;
}

bool insert_ecommerce_safe(List_ecommerce &Le, ecommerce xe) {
    if (is_ecommerce_exist(Le, xe.id_ecommerce)) {
        cout << "ID e-commerce yang dimasukkan sudah terdaftar!" << endl;
        return false;
    }

    adr_ecommerce pe = create_elemen_ecommerce(xe);
    insert_first_ecommerce(Le, pe);
    return true;
}

bool insert_toko_online_safe(adr_ecommerce pe, toko_online xt) {
    if (pe == NULL) {
        cout << "E-commerce tidak ditemukan!" << endl;
        return false;
    }

    if (is_toko_exist(first_toko_online(pe), xt.id_toko)) {
        cout << "ID toko online yang dimasukkan sudah terdaftar!" << endl;
        return false;
    }

    adr_toko_online pt = create_elemen_toko_online(xt);
    insert_last_toko_online(pe, pt);
    update_jumlah_toko(pe);
    return true;
}

void showList_toko_online(adr_ecommerce pe) {
    if (pe == NULL) {
        cout << "E-commerce tidak ditemukan!" << endl;
        return;
    }

    adr_toko_online pt = first_toko_online(pe);
    if (pt == NULL) {
        cout << "Tidak ada toko online di e-commerce ini." << endl;
        return;
    }

    cout << "Daftar Toko Online pada E-commerce: " << info(pe).nama_ecommerce << endl;
    while (pt != NULL) {
        cout << "ID Toko: " << info(pt).id_toko << endl;
        cout << "Nama Toko: " << info(pt).nama_toko << endl;
        cout << "Pemilik Toko: " << info(pt).pemilik_toko << endl;
        cout << "Total Produk: " << info(pt).total_product << endl;
        cout << "Lokasi: " << info(pt).lokasi << endl;
        cout << "--------------------------" << endl;
        pt = next_toko_online(pt);
    }
}

void showAllData(List_ecommerce Le) {
    adr_ecommerce pe = first(Le);
    if (pe == NULL) {
        cout << "Tidak ada data e-commerce." << endl;
        return;
    }

    while (pe != NULL) {
        cout << "ID E-commerce: " << info(pe).id_ecommerce << endl;
        cout << "Nama E-commerce: " << info(pe).nama_ecommerce << endl;
        cout << "Jumlah User: " << info(pe).jumlah_user << endl;
        cout << "Jumlah Toko: " << info(pe).jumlah_toko << endl;
        cout << "Biaya Layanan: " << info(pe).biaya_layanan << endl;
        cout << "--------------------------" << endl;


        showList_toko_online(pe);
        
        pe = next_ecommerce(pe);
    }
}


int countEcommerce(List_ecommerce Le) {
    int count = 0;
    adr_ecommerce pe = first(Le);
    while (pe != NULL) {
        count++;
        pe = next_ecommerce(pe);
    }
    return count;
}

