#include "stack.h"

int main() {
    Stack S;
    createStack_103012300245(S);

    int choice;
    char value;

    do {
        cout << "Menu:\n";
        cout << "1. Push (Tambahkan elemen ke stack)\n";
        cout << "2. Pop (Hapus elemen teratas dari stack)\n";
        cout << "3. Tampilkan isi stack\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (isFull_103012300245(S)) {
                    cout << "Stack penuh, tidak bisa menambahkan elemen baru.\n";
                } else {
                    cout << "Masukkan karakter untuk ditambahkan: ";
                    cin >> value;
                    push_103012300245(S, value);
                }
                break;
            case 2:
                if (isEmpty_103012300245(S)) {
                    cout << "Stack kosong, tidak ada elemen untuk dihapus.\n";
                } else {
                    cout << "Elemen yang dihapus: " << pop_103012300245(S) << endl;
                }
                break;
            case 3:
                cout << "Isi stack saat ini: ";
                printInfo_103012300245(S);
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Opsi tidak valid. Silakan pilih lagi.\n";
        }
    } while (choice != 4);
    return 0;
}
