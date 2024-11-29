#include "DLL.h"

void tampilkanList(list L) {
    address P = first(L);
    cout << "Daftar Lagu:\n";
    while (P != NULL) {
        cout << "Judul Lagu: " << info(P).judulLagu << ", Penulis: " << info(P).penulis << endl;
        P = next(P);
    }
    cout << endl;
}

int main() {
    list L;
    createList(L);
    
    int pilihan;
    do {
        cout << "=== Menu Double Linked List ===\n";
        cout << "1. Tambah Lagu di Awal\n";
        cout << "2. Tambah Lagu di Akhir\n";
        cout << "3. Hapus Lagu di Awal\n";
        cout << "4. Hapus Lagu di Akhir\n";
        cout << "5. Cari Lagu\n";
        cout << "6. Hapus Lagu berdasarkan Judul\n";
        cout << "7. Tampilkan List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                infotype lagu;
                cout << "Masukkan Judul Lagu (tanpa spasi): ";
                cin >> lagu.judulLagu;  
                cout << "Masukkan Penulis Lagu (tanpa spasi): ";
                cin >> lagu.penulis;

                address P;
                createNewElmt(lagu, P);
                insertFirst(L, P);
                break;
            }
            case 2: {
                infotype lagu;
                cout << "Masukkan Judul Lagu (tanpa spasi): ";
                cin >> lagu.judulLagu;
                cout << "Masukkan Penulis Lagu (tanpa spasi): ";
                cin >> lagu.penulis;

                address P;
                createNewElmt(lagu, P);
                insertLast(L, P);
                break;
            }
            case 3: {
                address P;
                deleteFirst(L, P);
                if (P != NULL) {
                    cout << "Lagu pertama dihapus: " << info(P).judulLagu << endl;
                }
                break;
            }
            case 4: {
                address P;
                deleteLast(L, P);
                if (P != NULL) {
                    cout << "Lagu terakhir dihapus: " << info(P).judulLagu << endl;
                }
                break;
            }
            case 5: {
                string judul;
                cout << "Masukkan Judul Lagu yang Dicari (tanpa spasi): ";
                cin >> judul;
                address P = findLagu(judul, L);
                if (P != NULL) {
                    cout << "Lagu ditemukan: " << info(P).judulLagu << " - " << info(P).penulis << endl;
                } else {
                    cout << "Lagu tidak ditemukan\n";
                }
                break;
            }
            case 6: {
                string judul;
                cout << "Masukkan Judul Lagu yang Akan Dihapus (tanpa spasi): ";
                cin >> judul;
                removeLagu(judul, L);
                break;
            }
            case 7: {
                tampilkanList(L);
                break;
            }
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
