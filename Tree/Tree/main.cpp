#include "tree.h"

int main() {
    int x[9] = {5, 3, 9, 10, 4, 7, 1, 8, 6};
    adrNode root = nullptr;

    for (int i = 0; i < 9; i++) {
        adrNode newNodePtr = newNode_103012300245(x[i]);
        insertNode_103012300245(root, newNodePtr);
    }

    cout << "Pre Order: ";
    printPreOrder_103012300245(root);
    cout << endl;

    cout << "Descendant of Node 9: ";
    printDescendant_103012300245(root, 9);
    cout << endl;

    cout << "Sum of BST Info: " << sumNode_103012300245(root) << endl;

    cout << "Number of Leaves: " << countLeaves_103012300245(root) << endl;

    cout << "Height of Tree: " << heightTree_103012300245(root) << endl;

    return 0;
}
