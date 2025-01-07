#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STACK_SIZE 50

char stack[STACK_SIZE];
int stackPointer = 0;

// prototypes
int Push(char letter);
char Pop();

int main(int argc, char* argv[argc+1])
{
    printf("Please enter a word to test if it's a palindrone: ");
    
    char buffer[STACK_SIZE];
    size_t charactersRead = 0;

    //scanf("%s",buffer); this stops once it reads a space. Is this what we really want? I don't htink so
    fgets(buffer, STACK_SIZE, stdin); // make sure to use fgets because it sets a limit on the number of characters to enter and prevents buffer overflow
    charactersRead = strcspn(buffer, "\n");
    buffer[charactersRead] = '\0'; // replace the new line character from the buffer with null terminating character
    
    for(size_t i = 0; i < charactersRead; i++)
    {
        if(!Push(buffer[i]))
        {
            printf("Error: Stackoverflow.");
            return EXIT_FAILURE;
        }
    }

    bool isPalindrone = true;
    for(size_t i = 0; i < charactersRead; i++)
    {
        char oppositeLetter = Pop();
        if(oppositeLetter == '\0')
            break;

        if(oppositeLetter != buffer[i])
        {
            isPalindrone = false;
            break;
        }
    }

    if(isPalindrone)
    {
        printf("%s is indeed a palindrone\n", buffer);
    }
    else 
    {
        printf("%s is NOT a palindrone\n", buffer);
    }

    return EXIT_SUCCESS;
}

int Push(char letter)
{
    if(stackPointer > STACK_SIZE - 1)
        return 0;

    stack[stackPointer] = letter;
    stackPointer++;

    return 1;
}

char Pop()
{
    stackPointer--;
    if (stackPointer < 0)
    {
        return '\0';
    }

    return stack[stackPointer];
}