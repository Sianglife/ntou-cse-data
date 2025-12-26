/*Date: 2025/12/26
Author: 黃鈺翔
Description: Compare two binary martix files and count the number of matching elements.
Using github copilot to write comments
*/
#include<stdio.h>

int getMaximumMatch(char *fNameA, char *fNameB) {
    FILE *fileA = fopen(fNameA, "r");
    FILE *fileB = fopen(fNameB, "r");
    if (fileA == NULL || fileB == NULL) {
        printf("Error opening files.\n");
        return -1;
    }

    int col = 0, row = 0; // current position in the matrix
    int collen = 0, rowlen = 0; // declare for dimensions of the matrix
    int mapA[100][100] = {0}, mapB[100][100] = {0}; // declare two 2D arrays to hold the binary matrices
    char bufferA[200], bufferB[200]; // buffers to read lines from files
    // Read file A into mapA
    while (fgets(bufferA, sizeof(bufferA), fileA) != NULL) {
        // Process each file line by line
        col = 0;
        for (int i = 0; bufferA[i] != '\0'; i++) {
            if (bufferA[i] == '0' || bufferA[i] == '1') {
                // just handle '0' and '1' characters and convert them to integers
                mapA[row][col] = bufferA[i] - '0'; // put into the 2D array
                col++;
            }
        }        
        row++;
    }

    // set dimensions as the fileA dimensions
    rowlen = row;
    collen = col;

    // Read file B into mapB
    row = 0;
    while (fgets(bufferB, sizeof(bufferB), fileB) != NULL) {
        // Process each file line by line
        col = 0;
        for (int i = 0; bufferB[i] != '\0'; i++) {
            if (bufferB[i] == '0' || bufferB[i] == '1') {
                mapB[row][col] = bufferB[i] - '0';
                col++;
            }
        }        
        row++;
    }
    fclose(fileA);
    fclose(fileB);

    // Compare the two maps
    int maxMatch = 0;
    for (int i = 0; i < rowlen; i++) {
        for (int j = 0; j < collen; j++) {
            if (mapA[i][j] == mapB[i][j]) {
                // count matching elements
                maxMatch++;
            }
        }
    }
    return maxMatch;
}

int main() {
    char *fileA = "fileA.txt";
    char *fileB = "fileB.txt";
    int result = getMaximumMatch(fileA, fileB);
    printf("%d\n", result);
    return 0;
}