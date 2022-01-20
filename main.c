#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 3
#define PASSWORD_LENGTH 100

void generatePassword( char password[PASSWORD_LENGTH], int size, const char* words[] );


/*
 * program generates 3 random passwords from an array of 10 words
 * function takes 3 parameters
 * character pointer (array), int (array size), array of const char pointers (array of words)
 * function generates password and stores it in the array
 * password must contain a randomly selected word from the array of words at a random location
 * and the rest of the password contains random printable characters
 */

int main() {
    printf("Passwords:\n\n");
    const char* words[] = {
            "golf",
            "hockey",
            "football",
            "dota",
            "paddle",
            "tennis",
            "longjump",
            "boxing",
            "mma",
            "shooting"
    };

    char password[PASSWORD_LENGTH];
    generatePassword(password, COUNT, words);
    printf("Password 1: %s\n", password );
    generatePassword(password, COUNT, words);
    printf("Password 2: %s\n", password );
    generatePassword(password, COUNT, words);
    printf("Password 3: %s\n", password );

    return 0;
}

void generatePassword( char password[PASSWORD_LENGTH], int size, const char* words[] )
{
    int wordNum = rand() % 11;
    int posNum = rand() % 3;
    int letterNum1 = rand() % 127;
    int letterNum2 = rand() % 127;
    int letterNum3 = rand() % 127;

    char* pos[15] = {
            letterNum1 +'0\0',
            letterNum2 +'0\0',
            letterNum3 +'0\0',
    };

    char* fmt[] = {
            "%s%c%c",
            "%c%s%c",
            "%c%c%s",
    };

    pos[posNum] = words[wordNum];
    sprintf( password, fmt[posNum], pos[0], pos[1], pos[2] );
}

