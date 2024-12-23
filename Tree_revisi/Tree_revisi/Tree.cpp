//
//  tree.cpp
//  Tree
//
//  Created by Falah Razan Hibrizi on 08/12/24.
//
#include "tree.h"

adrNode newNode_103012300245(infotype x){
    adrNode p = new node;
    info(p) = x;
    left(p) = nullptr;
    right(p) = nullptr;
    return p;
}

adrNode findNode_103012300245(adrNode root, infotype x){
    if (root == nullptr || info(root) == x) {
        return root;
    } else if (x < info(root)) {
        return findNode_103012300245(left(root), x);
    } else {
        return findNode_103012300245(right(root), x);
    }
}

void insertNode_103012300245(adrNode& root, adrNode p){
    if (root == nullptr) {
        root = p;
    } else if (info(p) < info(root)) {
        return insertNode_103012300245(left(root), p);
    } else {
        return insertNode_103012300245(right(root), p);
    }
}

void printPreOrder_103012300245(adrNode root){
    if (root != nullptr) {
        std::cout << info(root) << " ";
        printPreOrder_103012300245(left(root));
        printPreOrder_103012300245(right(root));
    }
}

void printDescendant_103012300245(adrNode root, infotype x){
    adrNode target = findNode_103012300245(root, x);
    if (target != nullptr) {
        printPreOrder_103012300245(left(target));
        printPreOrder_103012300245(right(target));
    }
}

int sumNode_103012300245(adrNode root){
    if (root == nullptr) return 0;
    return info(root) + sumNode_103012300245(left(root)) + sumNode_103012300245(right(root));
}

int countLeaves_103012300245(adrNode root){
    if (root == nullptr) return 0;
    if (left(root) == nullptr && right(root) == nullptr) return 1;
    return  countLeaves_103012300245(left(root)) + countLeaves_103012300245(right(root));
}

int heightTree_103012300245(adrNode root){
    if (root == nullptr){
        return  0;
    }
    int leftHeight = heightTree_103012300245(left(root));
    int rightHeight = heightTree_103012300245(right(root));
    
    if (leftHeight > rightHeight) {
        return 1 + leftHeight;
    } else {
        return 1 + rightHeight;
    }
}
