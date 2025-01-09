//gcc -o a palindrome-tester.c stack.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

// prototypes
void PopulateStack(char buffer[], size_t numberOfCharactersRead);
bool IsPalindrome(char buffer[], size_t numberOfCharactersRead, bool isDebug);
void PrintArrayAsHexAndChar(char array[], size_t arraySize, char message[]);
void RequestPalindrome(char buffer[], size_t* numberOfCharactersRead, bool isDebug);

#define BUFFER_SIZE 50

int main(int argc, char* argv[])
{
    bool isDebug = argc > 1 ? !strcmp(argv[1],"debug") : false;
    char buffer[BUFFER_SIZE];
    size_t numberOfCharactersRead = 0;

    if(!StackInitialize(BUFFER_SIZE))
    {
        puts("Could not initialize stack.");
        return EXIT_FAILURE;
    }

    RequestPalindrome(buffer, &numberOfCharactersRead, isDebug);
    PopulateStack(buffer, numberOfCharactersRead);
    IsPalindrome(buffer, numberOfCharactersRead, isDebug) ? printf("\n%s is indeed a palindrome\n", buffer) 
                                                          : printf("\n%s is NOT a palindrome\n", buffer);
    StackDestroy();
    return EXIT_SUCCESS;
}

void RequestPalindrome(char buffer[], size_t* numberOfCharactersRead, bool isDebug)
{
    printf("Please enter a word to test if it's a palindrome: ");
    fgets(buffer, BUFFER_SIZE, stdin); 
    *numberOfCharactersRead = strlen(buffer);

    if(isDebug) PrintArrayAsHexAndChar(buffer, BUFFER_SIZE,"Buffer before replacement");
    buffer[*numberOfCharactersRead-1] = '\0'; // replace line feed with null terminating character
    if(isDebug) PrintArrayAsHexAndChar(buffer, BUFFER_SIZE,"Buffer after replacement");

    return;
}

void PopulateStack(char buffer[], size_t numberOfCharactersRead)
{
    for(size_t i = 0; i < numberOfCharactersRead - 1; i++)
    {
        if(!StackIsFull())
        {
            DataFrame* data = (DataFrame*)malloc(sizeof(DataFrame));
            data->charData = buffer[i];
            StackPush(data);
        }
    }

    return;
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
        DataFrame* stackData = StackPop();

        if(isDebug) printf("stack: 0x%02x (%c)\t\tbuffer: 0x%02x (%c) \n", stackData->charData, stackData->charData, buffer[i], buffer[i]);

        if(stackData->charData != buffer[i])
        {
            isPalindrome = false;
            free(stackData);
            stackData = NULL;
            if(!isDebug) break;
        }
        free(stackData);
        stackData = NULL;
    }

    return isPalindrome;
}

void PrintArrayAsHexAndChar(char array[], size_t arraySize, char message[])
{
    printf("\n***************************\n%s: \n***************************\n", message);
    for(size_t i = 0; i < arraySize; i++)
    {
        switch(array[i])
        {
            case '\r':
                printf("hex: 0x%02x\t\tchar: \\r\n", array[i]);
                break;
            case '\n':
                printf("hex: 0x%02x\t\tchar: \\n\n", array[i]);
                break;
            default:
                printf("hex: 0x%02x\t\tchar: %c\n", array[i], array[i]);
        };            
    }

    return;
}