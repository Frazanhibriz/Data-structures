//
//  tree.h
//  Tree
//
//  Created by Falah Razan Hibrizi on 08/12/24.
//

#define info(P) P->info
#define left(P) P->left
#define right(P) P->right

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct node *adrNode;

struct node {
    infotype info;
    adrNode left;
    adrNode right;
};

typedef adrNode BinTree;

adrNode newNode_103012300245(infotype x);
adrNode findNode_103012300245(adrNode root, infotype x);
void insertNode_103012300245(adrNode& root, adrNode p);
void printPreOrder_103012300245(adrNode root);
void printDescendant_103012300245(adrNode root, infotype x);
int sumNode_103012300245(adrNode root);
int countLeaves_103012300245(adrNode root);
int heightTree_103012300245(adrNode root);
