#include<stdio.h>

int getMaximumMatch(char *fNameA, char *fNameB) {
    FILE *fileA = fopen(fNameA, "r");
    FILE *fileB = fopen(fNameB, "r");
    if (fileA == NULL || fileB == NULL) {
        printf("Error opening files.\n");
        return -1;
    }

    int col = 0, row = 0;
    int collen = 0, rowlen = 0;
    int mapA[100][100] = {0}, mapB[100][100] = {0};
    char bufferA[200], bufferB[200];
    // Read file A into mapA
    while (fgets(bufferA, sizeof(bufferA), fileA) != NULL) {
        // Process each file line by line
        col = 0;
        for (int i = 0; bufferA[i] != '\0'; i++) {
            if (bufferA[i] == '0' || bufferA[i] == '1') {
                mapA[row][col] = bufferA[i] - '0';
                col++;
            }
        }        
        row++;
    }

    // set dimensions
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