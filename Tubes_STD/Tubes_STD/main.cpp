#include "tubes_std.h"

void showMenu() {
    cout << "===================================" << endl;
    cout << "      Sistem E-commerce Manager    " << endl;
    cout << "===================================" << endl;
    cout << "1. Tambah E-commerce (Parent)" << endl;
    cout << "2. Hapus E-commerce (Parent)" << endl;
    cout << "3. Lihat Semua E-commerce (Parent)" << endl;
    cout << "4. Tambah Toko Online (Child)" << endl;
    cout << "5. Hapus Toko Online (Child)" << endl;
    cout << "6. Lihat Semua Toko Online (Child) untuk E-commerce tertentu" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilihan Anda: ";
}

int main() {
    List_ecommerce Le;
    createList_ecommerce(Le);
    int pilihan;

    do {
        showMenu();
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            ecommerce ec;
            cout << "Masukkan ID E-commerce: ";
            cin >> ec.id_ecommerce;
            cout << "Masukkan Nama E-commerce: ";
            cin >> ec.nama_ecommerce;
            cout << "Masukkan Jumlah User: ";
            cin >> ec.jumlah_user;
            cout << "Masukkan Jumlah Toko: ";
            cin >> ec.jumlah_toko;
            cout << "Masukkan Biaya Layanan: ";
            cin >> ec.biaya_layanan;

            adr_ecommerce pe = create_elemen_ecommerce(ec);
            insert_first_ecommerce(Le, pe);

            cout << "E-commerce berhasil ditambahkan!" << endl;
            break;
        }
        case 2: {
            adr_ecommerce pe;
            delete_last_ecommerce(Le, pe);
            if (pe != NULL) {
                cout << "E-commerce dengan ID " << info(pe).id_ecommerce << " berhasil dihapus!" << endl;
            } else {
                cout << "Tidak ada e-commerce yang bisa dihapus!" << endl;
            }
            break;
        }
        case 3: {
            showlist_ecommerce(Le);
            break;
        }
        case 4: {
            string id_ecommerce;
            cout << "Masukkan ID E-commerce untuk menambahkan toko: ";
            cin >> id_ecommerce;

            adr_ecommerce pe = search_ecommerce(Le, id_ecommerce);
            if (pe != NULL) {
                toko_online to;
                cout << "Masukkan ID Toko: ";
                cin >> to.id_toko;
                cout << "Masukkan Nama Toko: ";
                cin >> to.nama_toko;
                cout << "Masukkan Pemilik Toko: ";
                cin >> to.pemilik_toko;
                cout << "Masukkan Total Produk: ";
                cin >> to.total_product;
                cout << "Masukkan Lokasi: ";
                cin >> to.lokasi;

                adr_toko_online pt = create_elemen_toko_online(to);
                insert_last_toko_online(next_toko_online(pe), pt);

                cout << "Toko online berhasil ditambahkan!" << endl;
            } else {
                cout << "E-commerce dengan ID tersebut tidak ditemukan!" << endl;
            }
            break;
        }
        case 5: {
            string id_ecommerce;
            cout << "Masukkan ID E-commerce untuk menghapus toko: ";
            cin >> id_ecommerce;

            adr_ecommerce pe = search_ecommerce(Le, id_ecommerce);
            if (pe != NULL) {
                adr_toko_online pt;
                delete_first_toko_online(next_toko_online(pe), pt);
                if (pt != NULL) {
                    cout << "Toko online dengan ID " << info(pt).id_toko << " berhasil dihapus!" << endl;
                } else {
                    cout << "Tidak ada toko online yang bisa dihapus!" << endl;
                }
            } else {
                cout << "E-commerce dengan ID tersebut tidak ditemukan!" << endl;
            }
            break;
        }
        case 6: {
            string id_ecommerce;
            cout << "Masukkan ID E-commerce untuk melihat daftar toko: ";
            cin >> id_ecommerce;

            adr_ecommerce pe = search_ecommerce(Le, id_ecommerce);
            if (pe != NULL) {
                cout << "Daftar toko online untuk E-commerce " << info(pe).nama_ecommerce << ":" << endl;
                showlist_toko_online(pe);
            } else {
                cout << "E-commerce dengan ID tersebut tidak ditemukan!" << endl;
            }
            break;
        }
        case 7:
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }

        cout << endl;
    } while (pilihan != 7);

    return 0;
}
