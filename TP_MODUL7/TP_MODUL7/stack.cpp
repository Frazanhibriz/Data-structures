#include "stack.h"

void createStack_103012300245(Stack &S) {
    Top(S) = 0;
}

bool isEmpty_103012300245(Stack S) {
    return Top(S) == 0;
}

bool isFull_103012300245(Stack S) {
    return Top(S) == 15;
}

void push_103012300245(Stack &S, infotype x) {
    if (!isFull_103012300245(S)) {
        Top(S)++;
        info(S)[Top(S)] = x;
    }
}

infotype pop_103012300245(Stack &S) {
    infotype x = info(S)[Top(S)];
    Top(S)--;
    return x;
}

void printInfo_103012300245(Stack S) {
    for (int i = Top(S); i >= 1; i--) {
        cout << info(S)[i] << " ";
    }
    cout << endl;
}
