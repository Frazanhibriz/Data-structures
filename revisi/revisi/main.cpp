#include "test.h"

void menu_ecommerce(List_ecommerce &Le);
void menu_toko_online(adr_ecommerce pe);

int main() {
    List_ecommerce Le;
    createList_ecommerce(Le);

    int choice;
    do {
        cout << "\n===== MENU UTAMA =====" << endl;
        cout << "1. Kelola E-commerce (Parent)" << endl;
        cout << "2. Tampilkan semua data" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid! Masukkan angka." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                menu_ecommerce(Le);
                break;
            case 2:
                showAllData(Le);
                break;
            case 3:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}

void menu_ecommerce(List_ecommerce &Le) {
    int choice;
    do {
        cout << "\n===== MENU E-COMMERCE =====" << endl;
        cout << "1. Tambah E-commerce" << endl;
        cout << "2. Hapus E-commerce" << endl;
        cout << "3. Tampilkan Daftar E-commerce" << endl;
        cout << "4. Kelola Toko Online (Child)" << endl;
        cout << "5. Tampilkan jumlah data ecomerce" << endl;
        cout << "6. Kembali ke Menu Utama" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid! Masukkan angka." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                ecommerce xe;
                cout << "ID E-commerce: "; cin >> xe.id_ecommerce;
                cout << "Nama E-commerce: "; cin >> xe.nama_ecommerce;
                cout << "Jumlah User: "; cin >> xe.jumlah_user;
                cout << "Biaya Layanan: "; cin >> xe.biaya_layanan;
                xe.jumlah_toko = 0;

                if (insert_ecommerce_safe(Le, xe)) {
                    cout << "E-commerce berhasil ditambahkan!" << endl;
                }
                break;
            }
            case 2: {
                int delChoice;
                cout << "Hapus elemen: 1. First, 2. Last, 3. After" << endl;
                cout << "Pilih: ";
                cin >> delChoice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input tidak valid! Masukkan angka." << endl;
                    continue;
                }

                adr_ecommerce pe;
                string id_ecommerce;

                if (delChoice == 1) {
                    delete_first_ecommerce(Le, pe);
                } else if (delChoice == 2) {
                    delete_last_ecommerce(Le, pe);
                } else if (delChoice == 3) {
                    cout << "Masukkan ID E-commerce setelah elemen yang akan dihapus: ";
                    cin >> id_ecommerce;
                    adr_ecommerce prec = search_ecommerce(Le, id_ecommerce);
                    if (prec != NULL) {
                        delete_after_ecommerce(prec, pe);
                    } else {
                        cout << "ID E-commerce tidak ditemukan!" << endl;
                        break;
                    }
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                    break;
                }

                if (pe != NULL) {
                    cout << "E-commerce dengan ID " << info(pe).id_ecommerce << " berhasil dihapus!" << endl;
                } else {
                    cout << "Tidak ada elemen yang dihapus!" << endl;
                }
                break;
            }
            case 3:
                showlist_ecommerce(Le);
                break;
            case 4: {
                string id_ecommerce;
                cout << "Masukkan ID E-commerce untuk kelola toko online: ";
                cin >> id_ecommerce;

                adr_ecommerce pe = search_ecommerce(Le, id_ecommerce);
                if (pe != NULL) {
                    menu_toko_online(pe);
                } else {
                    cout << "E-commerce dengan ID tersebut tidak ditemukan!" << endl;
                }
                break;
            }
            case 5: {
                int count = countEcommerce(Le);
                cout << "Jumlah E-commerce: " << count << endl;
                break;
            }
            case 6:
                cout << "Kembali ke menu utama." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (choice != 6);
}

void menu_toko_online(adr_ecommerce pe) {
    int choice;
    do {
        cout << "\n===== MENU TOKO ONLINE =====" << endl;
        cout << "1. Tambah Toko Online" << endl;
        cout << "2. Hapus Toko Online" << endl;
        cout << "3. Tampilkan Daftar Toko Online" << endl;
        cout << "4. Kembali ke Menu E-commerce" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid! Masukkan angka." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                toko_online xt;
                cout << "ID Toko: "; cin >> xt.id_toko;
                cout << "Nama Toko: "; cin >> xt.nama_toko;
                cout << "Pemilik Toko: "; cin >> xt.pemilik_toko;
                cout << "Total Produk: "; cin >> xt.total_product;
                cout << "Lokasi: "; cin >> xt.lokasi;

                if (insert_toko_online_safe(pe, xt)) {
                    cout << "Toko online berhasil ditambahkan!" << endl;
                }
                break;
            }
            case 2: {
                int delChoice;
                cout << "Hapus elemen: 1. First, 2. Last, 3. After" << endl;
                cout << "Pilih: ";
                cin >> delChoice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input tidak valid! Masukkan angka." << endl;
                    continue;
                }

                adr_toko_online pt = nullptr;
                string id_toko;

                if (delChoice == 1) {
                    delete_first_toko_online(pe, pt);
                } else if (delChoice == 2) {
                    delete_last_toko_online(pe, pt);
                } else if (delChoice == 3) {
                    cout << "Masukkan ID Toko setelah elemen yang akan dihapus: ";
                    cin >> id_toko;
                    adr_toko_online prec = first_toko_online(pe);

                    while (prec != NULL && next_toko_online(prec) != NULL) {
                        if (info(next_toko_online(prec)).id_toko == id_toko) {
                            delete_after_toko_online(prec, pt);
                            break;
                        }
                        prec = next_toko_online(prec);
                    }

                    if (prec == NULL || next_toko_online(prec) == NULL) {
                        cout << "ID Toko tidak ditemukan setelah elemen tersebut!" << endl;
                        break;
                    }
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                    break;
                }

                if (pt != NULL) {
                    cout << "Toko online dengan ID " << info(pt).id_toko << " berhasil dihapus!" << endl;
                } else {
                    cout << "Tidak ada elemen yang dihapus!" << endl;
                }
                update_jumlah_toko(pe); 
                break;
            }
            case 3:
                showList_toko_online(pe);
                break;
            case 4:
                cout << "Kembali ke menu e-commerce." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (choice != 4);
}
