#include <stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)


int main() {
    const int MAXSIZE = 100;
    int fileA[MAXSIZE], fileB[MAXSIZE], fileC[MAXSIZE];

    FILE* fA, * fB, * fC;
    if ((fA = fopen("fileA.txt", "r")) == NULL)
        return -1;
    else if ((fB = fopen("fileB.txt", "r")) == NULL)
        return -1;

    fC = fopen("fileC.txt", "w");
    int size = 0;
    char buffer;
    while (!feof(fA)) {
        buffer = fgetc(fA);
        if (buffer == ' ') {
            size++;
        }
    }
    size += 1;
    fseek(fA, 0, 0);

    while (!feof(fA) && !feof(fB)) {
        for (int i = 0; i < size; i++) {
            fscanf(fA, "%d", &fileA[i]);
            fscanf(fB, "%d", &fileB[i]);
        }
    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += fileA[i];
        sum += fileB[i];
    }
    fileC[0] = sum;
    fprintf(fC, "%d ", fileC[0]);
    fclose(fA);
    fclose(fB);
    fclose(fC);
}
