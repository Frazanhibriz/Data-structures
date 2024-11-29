//
//  main.cpp
//  TP_MODUL5
//
//  Created by Falah Razan Hibrizi on 13/10/24.
//

#include <iostream>
#include "menu.h"

int main() {
    list L;
    create_list_103012300245(L);
    int pilihan, k;
    char data;
    
    pilihan = menu_103012300245();

    
    while (pilihan != 0) {

        switch (pilihan) {
            case 1:
                cout << "Masukkan data karakter: ";
                cin >> data;
                insert_last_103012300245(L, new_node_103012300245(data));
                break;
            case 2:
                cout << "Data dalam list: ";
                show_data_103012300245(L);
                break;
            case 3:
                cout << "Persentase konsonan: " << consonant_percentage_103012300245(L) << "%" << endl;
                break;
            case 4:
                cout << "Masukkan nilai k: ";
                cin >> k;
                show_first_k_103012300245(L, k);
                break;
            case 0:
                cout << "Keluar program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
        pilihan = menu_103012300245();
    }

    return 0;
}
