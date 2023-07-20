#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define SIZE 100

int main()
{
    int num;
    cout << "Enter num: ";
    cin >> num;

    FILE* file;
    fopen_s(&file, "a.txt", "r");

    float arr[SIZE], diff[SIZE];
    int count = 0;

    for (int i = 0; !feof(file); i++)
    {
        fscanf_s(file, "%f", &arr[i]);
        count++;
    }

    float min_dif = abs(arr[0] - num);
    int poz = 1;
    for (int i = 0; i < count; i++)
    {
        if (abs(arr[i] - num) < min_dif)
        {
            min_dif = abs(arr[i] - num);
            poz = i+1;
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%f ", arr[i]);
    }

    printf("\n%d\n", poz);

    fclose(file);
}