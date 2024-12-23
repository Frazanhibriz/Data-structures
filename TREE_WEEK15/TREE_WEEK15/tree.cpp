#include "tree.h"
#include <iostream>
using namespace std;

adrNode newNode_103012300245(infotype x) {
    adrNode p = new node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode_103012300245(adrNode &root, adrNode p) {
    if (root == NULL) {
        root = p;
    } else {
        if (p->info < root->info) {
            insertNode_103012300245(root->left, p);
        } else {
            insertNode_103012300245(root->right, p);
        }
    }
}

adrNode findMin_103012300245(adrNode root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void DeleteNode_103012300245(adrNode &root, adrNode &p) {
    if (root == NULL) {
        return;
    }
    
    if (p->info < root->info) {
        DeleteNode_103012300245(root->left, p);
    } else if (p->info > root->info) {
        DeleteNode_103012300245(root->right, p);
    } else {
        
        adrNode temp;
        

        if (root->left == NULL) {
            temp = root->right;
            delete root;
            root = temp;
        } else if (root->right == NULL) {
            temp = root->left;
            delete root;
            root = temp;
        } else {

            temp = findMin_103012300245(root->right);
            root->info = temp->info;
            

            adrNode toDelete = newNode_103012300245(temp->info);
            DeleteNode_103012300245(root->right, toDelete);
        }
    }
}

void printInOrder_103012300245(adrNode root) {
    if (root != NULL) {
        printInOrder_103012300245(root->left);
        cout << root->info << " ";
        printInOrder_103012300245(root->right);
    }
}
