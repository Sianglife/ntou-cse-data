/*Date: 2025/12/26
Author: 黃鈺翔
Description: Compare two text files containing IDs and output the matching IDs in the order of the second file.
Using github copilot to write comments
*/
#include<stdio.h>
#include<string.h>

int main() {
    char *fileA = "fileA.txt";
    char *fileB = "fileB.txt";
    FILE *fA = fopen(fileA, "r");
    FILE *fB = fopen(fileB, "r");

    if (fA == NULL || fB == NULL) {
        printf("Error opening files.\n");
        return -1;
    }

    char idsA[100][50], idsB[100][50]; // Arrays to hold IDs from both files
    int countA = 0, countB = 0; // Counters for number of IDs in each file
    // Read IDs from file A
    while(fscanf(fA, "%s", idsA[countA]) == 1) {
        countA++;
    }

    // Read IDs from file B
    while(fscanf(fB, "%s", idsB[countB]) == 1) {
        countB++;
    }

    fclose(fA);
    fclose(fB);

    // Compare IDs from both files and count matches
    char matches[100][50];
    int matchCount = 0;
    for(int j = 0; j < countB; j++) {
        for(int i = 0; i < countA; i++) {
            if(strcmp(idsA[i], idsB[j]) == 0) {
                // Output as the order of fileB
                strcpy(matches[matchCount], idsA[i]);
                matchCount++;
                break; // Move to the next ID in file A after a match
            }
        }
    }

    // Print matched IDs
    for(int i = 0; i < matchCount; i++) {
        printf("%s\n", matches[i]);
    }
    return 0;
}