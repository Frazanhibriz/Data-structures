#ifndef STACK_H
#define STACK_H
#define Top(S) (S).Top
#define info(S) (S).info

#include <iostream>
using namespace std;

typedef char infotype;

struct Stack {
    infotype info[15];
    int Top;
};

void createStack_103012300245(Stack &S);
bool isEmpty_103012300245(Stack S);
bool isFull_103012300245(Stack S);
void push_103012300245(Stack &S, infotype x);
infotype pop_103012300245(Stack &S);
void printInfo_103012300245(Stack S);

#endif
