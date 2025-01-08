#include <stdlib.h>
#include "stack.h"

StackStructure stackStructure;
bool stackInitialized = false;

int StackInitialize(int stackSize)
{
    if(!stackInitialized)
        stackStructure.stack = (DataFrame**)malloc(stackSize * sizeof(DataFrame*));
    else
        stackStructure.stack = (DataFrame**)realloc(stackStructure.stack,stackSize * sizeof(DataFrame*));

    if(stackStructure.stack == NULL)
        return 0;

    stackStructure.stackSize = stackSize;
    return 1;
}

void StackDestroy()
{
    free(stackStructure.stack);
    stackStructure.stack == NULL;
}

void StackPush(DataFrame* frame)
{
    stackStructure.stackPointer++;
    stackStructure.stack[stackStructure.stackPointer] = frame;
}

DataFrame* StackPop()
{
    DataFrame* frame = stackStructure.stack[stackStructure.stackPointer];
    stackStructure.stackPointer--;

    return frame;
}

bool StackIsFull()
{
    return stackStructure.stackPointer == stackStructure.stackSize;
}

bool StackIsEmpty()
{
    return stackStructure.stackPointer <  0;
}