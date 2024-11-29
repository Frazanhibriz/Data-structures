#include "menu.h"

#define first(L) L.first
#define info(P) P->info
#define next(P) P->next

void create_list_103012300245(list &L) {
    first(L) = NULL;
}

address new_node_103012300245(infotype x) {
    address P = new node;
    next(P) = NULL;
    info(P) = x;
    return P;
}

void insert_last_103012300245(list &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        address Q = first(L);
        
        while (next(Q) != NULL) {
            Q = next(Q);
        }
    
        next(Q) = P;
    }
}


void show_data_103012300245(list L) {
    address p = first(L);

    while (p != NULL) {
        cout << info(p) << " ";
        p = next(p);
    }
    cout << endl;
}


float consonant_percentage_103012300245(list L) {
    int totalChars = 0;
    int consonantCount = 0;
    address P = first(L);

    while (P != NULL) {
        char c = info(P);
    
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            totalChars++;
            if (c != 'a' && c != 'i' && c != 'u' && c != 'e' && c != 'o' &&
                c != 'A' && c != 'I' && c != 'U' && c != 'E' && c != 'O') {
                consonantCount++;
            }
        }

        P = next(P);
    }

    if (totalChars == 0) return 0;
    return (consonantCount * 100.0) / totalChars;
}

void show_first_k_103012300245(list L, int k) {
    address p = first(L);
    int index = 1;

    while (p != NULL && index < k) {
        p = next(p);
        index++;
    }

    if (p != NULL) {
        cout << "Data ke-" << k << " adalah: " << info(p) << endl;
    } else {
        cout << "Tidak ada elemen data ke-" << k << endl;
    }
}

int menu_103012300245() {
    int pilih = 0;
    
    cout << "==============MENU==============" << endl;
    cout << "1. Tambah data" << endl;
    cout << "2. Tampilkan semua data" << endl;
    cout << "3. Hitung persentase konsonan" << endl;
    cout << "4. Tampil karakter ke-k" << endl;
    cout << "0. Keluar" << endl;
    cout << "================================" << endl;
    
    cout << "Silahkan pilih: ";
    cin >> pilih;
    
    return pilih;
}
