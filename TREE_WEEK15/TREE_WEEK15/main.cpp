#include "tree.h"
#include <iostream>
using namespace std;

int main() {
    adrNode root = NULL;
    
    int values[] = {8, 4, 12, 6, 9, 15, 7, 13, 17};
    for (int val : values) {
        adrNode p = newNode_103012300245(val);
        insertNode_103012300245(root, p);
    }
    
    int deleteValues[] = {8, 9, 12, 13, 15, 17, 7, 6, 4};
    
    cout << "Initial tree: ";
    printInOrder_103012300245(root);
    cout << endl;
    
    for (int val : deleteValues) {
        adrNode p = newNode_103012300245(val);
        DeleteNode_103012300245(root, p);
        if (root == NULL) {
            cout << "(kosong)" << endl;
        } else {
            printInOrder_103012300245(root);
            cout << endl;
        }
    }
    
    return 0;
}
