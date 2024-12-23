#ifndef TREE_H
#define TREE_H


typedef int infotype;
typedef struct node *adrNode;

struct node {
    infotype info;
    adrNode left;
    adrNode right;
};

adrNode newNode_103012300245(infotype x);
void insertNode_103012300245(adrNode &root, adrNode p);
void DeleteNode_103012300245(adrNode &root, adrNode &p);
void printInOrder_103012300245(adrNode root);
adrNode findMin_103012300245(adrNode root);

#endif
