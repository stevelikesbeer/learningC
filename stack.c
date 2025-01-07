#include "stack.h"

char stack[STACK_SIZE];
int stackPointer = -1;

void Push(char letter)
{
    stackPointer++;
    stack[stackPointer] = letter;
}

char Pop()
{
    char character = stack[stackPointer];
    stackPointer--;

    return character;
}

bool StackIsFull()
{
    return stackPointer == STACK_SIZE;
}

bool StackIsEmpty()
{
    return stackPointer <  0;
}