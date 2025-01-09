#include <stdlib.h>
#include "stack.h"

StackStructure stackStructure = {.stack = NULL, .stackPointer = -1};

int StackInitialize(int stackSize)
{
    stackStructure.stack = !stackStructure.stack ? (DataFrame**)malloc(stackSize * sizeof(DataFrame*))
                                                 : (DataFrame**)realloc(stackStructure.stack,stackSize * sizeof(DataFrame*));

    if(stackStructure.stack == NULL)
        return 0;

    stackStructure.stackSize = stackSize;

    return 1;
}

void StackDestroy()
{
    free(stackStructure.stack);
    stackStructure.stack == NULL;

    return;
}

void StackPush(DataFrame* frame)
{
    stackStructure.stackPointer++;
    stackStructure.stack[stackStructure.stackPointer] = frame;

    return;
}

DataFrame* StackPop()
{
    DataFrame* frame = stackStructure.stack[stackStructure.stackPointer];
    stackStructure.stackPointer--;

    return frame;
}

bool StackIsFull()
{
    return stackStructure.stackPointer == (stackStructure.stackSize -1);
}

bool StackIsEmpty()
{
    return stackStructure.stackPointer <  0;
}