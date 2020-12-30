// Name: Vuochlang Chang
// Class: CSE 121, Assignment 5
// Date: 12/06/2018

#include "all.h"

int xorEncrypt(FILE *disk) {

    unsigned long int fileSize; // size in bytes
    int length; // length of the key[]
    char *fileBuffer = NULL;
    char key[] = "XorEnc223423";

    length = strlen(key);
    fseek(disk, 0, SEEK_END); // move to the end of the file
    fileSize = ftell(disk);
    fileBuffer = malloc(fileSize); // malloc size according to the file size
    rewind(disk); // move back to the beginning

    if( fread(fileBuffer, fileSize, 1, disk) !=1) {
        printf("Error, cannot read the file.\n");
        return -1;
    }
    for ( int i = 0; i < fileSize; i++) {
        fileBuffer[i] = fileBuffer[i] ^ key[i % length]; // XOR encryption step
    }
    rewind(disk);
    if( fwrite(fileBuffer, fileSize, 1, disk)!=1) { // Write encrypted bytes, fileBuffer, back to disk
        printf("Error in writing encrypted data to file \n");
        return -1;
    }
    free(fileBuffer); // returning RAM memory back to the system
    return 0;
}

