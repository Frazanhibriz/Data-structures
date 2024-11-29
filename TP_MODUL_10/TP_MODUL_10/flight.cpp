#include "flight.h"
#include <iostream>

void createListJadwal_103012300245(ListJadwal &L) {
    first(L) = nullptr;
}

adr_jadwalIP createElemenJadwal_103012300245(infotype x) {
    adr_jadwalIP q = new elemenJadwal;
    info(q) = x;
    next(q) = nullptr;
    return q;
}

void insertLastJ_103012300245(ListJadwal &L, adr_jadwalIP P) {
    if (first(L) == nullptr) {
        first(L) = P;
    } else {
        adr_jadwalIP Q = first(L);
        while (next(Q) != nullptr) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void showJadwal_103012300245(ListJadwal L) {
    adr_jadwalIP q = first(L);
    if (q == nullptr) {
        cout << "List jadwal kosong" << endl;
    } else {
        cout << "Daftar Jadwal Penerbangan: " << endl;
        while (q != nullptr) {
            cout << "[Kode: " << info(q).kode
                 << ", Jenis: " << info(q).jenis
                 << ", Tanggal: " << info(q).tanggal
                 << ", Waktu: " << info(q).waktu
                 << ", Asal: " << info(q).asal
                 << ", Tujuan: " << info(q).tujuan
                 << ", Kapasitas: " << info(q).kapasitas
                 << "] ";
            q = next(q);
        }
        cout << endl;
    }
}

void deleteFirstJ_103012300245(ListJadwal &L, adr_jadwalIP &P) {
    if (first(L) == nullptr) {
        cout << "List kosong, tidak ada elemen yang dapat dihapus." << endl;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = nullptr;
        delete P;
    }
}

bool searchJ_103012300245(ListJadwal L, string dari, string ke, string tanggal) {
    adr_jadwalIP q = first(L);
    while (q != nullptr) {
        if (info(q).asal == dari && info(q).tujuan == ke && info(q).tanggal == tanggal) {
            return true;
        }
        q = next(q);
    }
    return false;
}
