#include <iostream>
#include "flight.h"

int main() {
    ListJadwal L;
    int n;
    adr_jadwalIP deletedElemen;

    createListJadwal_103012300245(L);
    cin >> n;

    for (int i = 0; i < n; i++) {
        jadwalPenerbangan jadwal;
        cout << "Input jadwal ke-" << i + 1 << endl;
        cout << "Kode penerbangan: ";
        cin >> jadwal.kode;
        cout << "Jenis penerbangan: ";
        cin >> jadwal.jenis;
        cout << "Tanggal penerbangan: ";
        cin >> jadwal.tanggal;
        cout << "Waktu penerbangan (format HH:MM): ";
        cin >> jadwal.waktu;
        cout << "Asal penerbangan: ";
        cin >> jadwal.asal;
        cout << "Tujuan penerbangan: ";
        cin >> jadwal.tujuan;
        cout << "Kapasitas penumpang: ";
        cin >> jadwal.kapasitas;

        adr_jadwalIP elemen = createElemenJadwal_103012300245(jadwal);
        insertLastJ_103012300245(L, elemen);
    }

    cout << "\nDaftar semua jadwal penerbangan:" << endl;
    showJadwal_103012300245(L);

    deleteFirstJ_103012300245(L, deletedElemen);
    cout << "\nDaftar jadwal setelah penghapusan elemen pertama:" << endl;
    showJadwal_103012300245(L);

    string dari = "Surabaya", ke = "Malang", tanggal = "2022-12-09";
    cout << "\nMencari jadwal penerbangan dari " << dari
         << " ke " << ke << " pada tanggal " << tanggal << endl;

    bool found = searchJ_103012300245(L, dari, ke, tanggal);
    if (found) {
        cout << "Jadwal ditemukan!" << endl;
    } else {
        cout << "Jadwal tidak ditemukan!" << endl;
    }

    return 0;
}
