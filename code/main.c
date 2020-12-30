// Name: Vuochlang Chang
// Class: CSE 121, Assignment 5
// Date: 12/06/2018

#include "all.h"

int main (void) {

    FILE *fp;
    int num;
    char fileName[20];

    printf("Enter file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r+");
    if(fp == NULL) {
        printf("File does not exist\n");
        return 0;
    }
    if(xorEncrypt(fp) == -1) {
        printf("Encrypted < %s > fail!!\n", fileName);
    }
    else {
        printf("Encrypted < %s > sucessful!\n", fileName);
    }
    fclose(fp);
    return 0;
}