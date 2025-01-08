#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef union {
    char charData;
    int intData;
    char stringData[500];
    double doubleData; 
} DataFrame;

typedef struct {
    DataFrame** stack;
    int stackPointer;
    int stackSize;
} StackStructure;

int StackInitialize(int stackSize);
void StackDestroy();
void StackPush(DataFrame* frame);
DataFrame* StackPop();
bool StackIsFull();
bool StackIsEmpty();

#endif