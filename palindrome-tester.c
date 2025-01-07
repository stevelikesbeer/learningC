//gcc -o a palindrome-tester.c stack.c -D STACK_SIZE=50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

// prototypes
void PopulateStack(char buffer[], size_t numberOfCharactersRead);
bool IsPalindrome(char buffer[], size_t numberOfCharactersRead, bool isDebug);
void PrintArrayAsHexAndChar(char array[], size_t arraySize, char message[]);

int main(int argc, char* argv[argc+1])
{
    bool IsDebug = argc > 1 ? !strcmp(argv[1],"debug") : false;
    char buffer[STACK_SIZE];
    size_t numberOfCharactersRead = 0;

    printf("Please enter a word to test if it's a palindrome: ");
    fgets(buffer, STACK_SIZE, stdin); 
    numberOfCharactersRead = strlen(buffer);

    if(IsDebug) PrintArrayAsHexAndChar(buffer, STACK_SIZE,"Buffer before replacement");
    buffer[numberOfCharactersRead-1] = '\0'; // replace line feed with null terminating character
    if(IsDebug) PrintArrayAsHexAndChar(buffer, STACK_SIZE,"Buffer after replacement");

    PopulateStack(buffer, numberOfCharactersRead);
    IsPalindrome(buffer, numberOfCharactersRead, IsDebug) ? printf("\n%s is indeed a palindrome\n", buffer) 
                                                          : printf("\n%s is NOT a palindrome\n", buffer);

    return EXIT_SUCCESS;
}

void PrintArrayAsHexAndChar(char array[], size_t arraySize, char message[])
{
    printf("\n***************************\n%s: \n***************************\n", message);
    for(size_t i = 0; i < arraySize; i++)
    {
        if ( array[i] == '\r')  // if it's a carriage return, convert it to text
            printf("hex: 0x%02x\t\tchar: \\r\n", array[i]);
        else if (array[i] == '\n') // if its a line feed, convert it to text
            printf("hex: 0x%02x\t\tchar: \\n\n", array[i]);
        else
            printf("hex: 0x%02x\t\tchar: %c\n", array[i], array[i]);
    }
}

void PopulateStack(char buffer[], size_t numberOfCharactersRead)
{
    for(size_t i = 0; i < numberOfCharactersRead - 1; i++)
    {
        if(!StackIsFull())
            Push(buffer[i]);
    }
}

bool IsPalindrome(char buffer[], size_t numberOfCharactersRead, bool isDebug)
{
    if(isDebug) puts("\nComparing stack to buffer");

    bool isPalindrome = true;
    for(size_t i = 0; i < numberOfCharactersRead - 1; i++)
    {
        if(StackIsEmpty())
        {
            isPalindrome = false;
            break;
        }
        char oppositeLetter = Pop();

        if(isDebug) printf("stack: 0x%02x (%c)\t\tbuffer: 0x%02x (%c) \n", oppositeLetter, oppositeLetter, buffer[i], buffer[i]);

        if(oppositeLetter != buffer[i])
        {
            isPalindrome = false;
            if(!isDebug) break;
        }
    }

    return isPalindrome;
}