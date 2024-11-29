#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

typedef char infotype;
typedef struct node *address;

struct node {
    infotype info;
    address next;
};

struct list {
    address first;
};


void create_list_103012300245(list &L);
address new_node_103012300245(infotype x);
void insert_last_103012300245(list &L, address P);
void show_data_103012300245(list L);
float consonant_percentage_103012300245(list L);
void show_first_k_103012300245(list L, int k);
int menu_103012300245();


#endif
