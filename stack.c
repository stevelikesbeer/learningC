#include "stack.h"

DataFrame* stack[STACK_SIZE];
int stackPointer = -1;

void Push(DataFrame* frame)
{
    stackPointer++;
    stack[stackPointer] = frame;
}

DataFrame* Pop()
{
    DataFrame* frame = stack[stackPointer];
    stackPointer--;

    return frame;
}

bool StackIsFull()
{
    return stackPointer == STACK_SIZE;
}

bool StackIsEmpty()
{
    return stackPointer <  0;
}