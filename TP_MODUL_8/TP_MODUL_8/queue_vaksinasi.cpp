#define nil NULL
#include "queue_vaksinasi.h"

void createQueue_103012300245(Queue &Q) {
    head(Q) = nil;
    tail(Q) = nil;
}

bool isEmpty_103012300245(Queue Q) {
    return head(Q) == nil;
}

ElemQ* createElemQueue_103012300245(string nama, int usia, string pekerjaan, int nomor_antrian) {
    ElemQ* P = new ElemQ;
    info(P).nama = nama;
    info(P).usia = usia;
    info(P).pekerjaan = pekerjaan;
    info(P).prioritas = (usia >= 60 || pekerjaan == "tenaga kesehatan");
    info(P).nomor_antrean = nomor_antrian;
    info(P).kondisi_darurat = false;
    info(P).waktu_daftar = 0;
    next(P) = nil;
    return P;
}

void enqueue_103012300245(Queue &Q, ElemQ *P) {
    if (isEmpty_103012300245(Q)) {
        head(Q) = P;
        tail(Q) = P;
    } else if (info(P).prioritas) {
        if (!info(head(Q)).prioritas) {
            next(P) = head(Q);
            head(Q) = P;
        } else {
            ElemQ *temp = head(Q);
            while (next(temp) != nil && info(next(temp)).prioritas) {
                temp = next(temp);
            }
            next(P) = next(temp);
            next(temp) = P;
            if (next(P) == nil) {
                tail(Q) = P;
            }
        }
    } else {
        next(tail(Q)) = P;
        tail(Q) = P;
    }
}

void dequeue_103012300245(Queue &Q, ElemQ *&P) {
    if (isEmpty_103012300245(Q)) {
        P = nil;
        cout << "Semua warga telah terlayani." << endl;
    } else {
        P = head(Q);
        head(Q) = next(head(Q));
        if (head(Q) == nil) {
            tail(Q) = nil;
        }
        next(P) = nil;
    }
}

ElemQ* front_103012300245(Queue Q) {
    return head(Q);
}

ElemQ* back_103012300245(Queue Q) {
    return tail(Q);
}

int size_103012300245(Queue Q) {
    int count = 0;
    ElemQ *temp = head(Q);
    while (temp != nil) {
        count++;
        temp = next(temp);
    }
    return count;
}

void printInfo_103012300245(Queue Q) {
    ElemQ *temp = head(Q);
    while (temp != nil) {
        cout << "Nama: " << info(temp).nama << ", Usia: " << info(temp).usia
             << ", Pekerjaan: " << info(temp).pekerjaan << ", Prioritas: " << info(temp).prioritas
             << ", Nomor Antrean: " << info(temp).nomor_antrean << ", Kondisi Darurat: " << info(temp).kondisi_darurat
             << endl;
        temp = next(temp);
    }
}

void serveQueue_103012300245(Queue &Q) {
    int count = 0;
    ElemQ *P;
    while (!isEmpty_103012300245(Q) && count < 100) {
        dequeue_103012300245(Q, P);
        cout << "Warga dengan nomor antrean " << info(P).nomor_antrean << " telah dilayani." << endl;
        count++;
    }
    if (count == 100) {
        cout << "Kapasitas telah penuh. Warga yang belum terlayani diminta kembali besok." << endl;
    } else if (isEmpty_103012300245(Q)) {
        cout << "Semua warga telah terlayani." << endl;
    }
}

void reassignQueue_103012300245(Queue &Q) {
    ElemQ *temp = head(Q);
    while (temp != nil) {
        if (!info(temp).prioritas) {
            info(temp).prioritas = (info(temp).usia >= 60 || info(temp).pekerjaan == "tenaga kesehatan");
        }
        temp = next(temp);
    }
}

void checkWaitingTime_103012300245(Queue &Q, int waktu_sekarang) {
    ElemQ *temp = head(Q);
    while (temp != nil) {
        if (waktu_sekarang - info(temp).waktu_daftar > 120 && !info(temp).prioritas) {
            info(temp).prioritas = true;
        }
        temp = next(temp);
    }
}

void emergencyHandle_103012300245(Queue &Q, int nomor_antrean) {
    ElemQ *temp = head(Q);
    ElemQ *prev = nil;
    while (temp != nil && info(temp).nomor_antrean != nomor_antrean) {
        prev = temp;
        temp = next(temp);
    }
    if (temp != nil) {
        info(temp).kondisi_darurat = true;
        if (prev != nil) {
            next(prev) = next(temp);
            next(temp) = head(Q);
            head(Q) = temp;
        }
        cout << "Warga dengan nomor antrean " << nomor_antrean << " diprioritaskan ke depan antrean." << endl;
    } else {
        cout << "Warga dengan nomor antrean tersebut tidak ada dalam antrean." << endl;
    }
}

void updatePriority_103012300245(Queue &Q) {
    ElemQ *temp = head(Q);
    while (temp != nil) {
        if (info(temp).kondisi_darurat) {
            emergencyHandle_103012300245(Q, info(temp).nomor_antrean);
        } else if (!info(temp).prioritas && info(temp).waktu_daftar > 120) {
            info(temp).prioritas = true;
        }
        temp = next(temp);
    }
}

ElemQ* findAndRemove_103012300245(Queue &Q, int nomor_antrean) {
    ElemQ *temp = head(Q);
    ElemQ *prev = nil;
    while (temp != nil && info(temp).nomor_antrean != nomor_antrean) {
        prev = temp;
        temp = next(temp);
    }
    if (temp != nil) {
        if (prev == nil) {
            head(Q) = next(temp);
        } else {
            next(prev) = next(temp);
        }
        if (next(temp) == nil) {
            tail(Q) = prev;
        }
        next(temp) = nil;
        return temp;
    }
    cout << "Warga dengan nomor antrean tersebut tidak ada dalam antrean." << endl;
    return nil;
}
