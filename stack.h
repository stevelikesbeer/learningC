#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef union {
    char charData;
    int intData;
    char stringData[500];
    double doubleData; 
} DataFrame;

void Push(DataFrame* frame);
DataFrame* Pop();
bool StackIsFull();
bool StackIsEmpty();

#endif