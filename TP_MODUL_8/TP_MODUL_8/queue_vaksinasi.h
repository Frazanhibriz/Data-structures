#ifndef QUEUE_VAKSINASI_H
#define QUEUE_VAKSINASI_H
#define info(P) (P->info)
#define next(P) (P->next)
#define head(Q) ((Q).head)
#define tail(Q) ((Q).tail)

#include <iostream>
#include <string>
using namespace std;

typedef struct ElemQ *address;

struct Queue {
    ElemQ *head;
    ElemQ *tail;
};

struct infotype {
    string nama;
    int usia;
    string pekerjaan;
    bool prioritas;
    int nomor_antrean;
    bool kondisi_darurat;
    int waktu_daftar;
};

struct ElemQ {
    infotype info;
    ElemQ *next;
};

void createQueue_103012300245(Queue &Q);
bool isEmpty_103012300245(Queue Q);
ElemQ* createElemQueue_103012300245(string nama, int usia, string pekerjaan, int nomor_antrian);
void enqueue_103012300245(Queue &Q, ElemQ *P);
void dequeue_103012300245(Queue &Q, ElemQ *&P);
ElemQ* front_103012300245(Queue Q);
ElemQ* back_103012300245(Queue Q);
int size_103012300245(Queue Q);
void printInfo_103012300245(Queue Q);
void serveQueue_103012300245(Queue &Q);
void reassignQueue_103012300245(Queue &Q);
void checkWaitingTime_103012300245(Queue &Q, int waktu_sekarang);
void emergencyHandle_103012300245(Queue &Q, int nomor_antrean);
void updatePriority_103012300245(Queue &Q);
ElemQ* findAndRemove_103012300245(Queue &Q, int nomor_antrean);

#endif
