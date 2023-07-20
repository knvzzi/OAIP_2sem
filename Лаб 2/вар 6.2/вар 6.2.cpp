#include <iostream>
#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

int main() {
	setlocale(LC_ALL, "Rus");
	FILE* F1;
	FILE* F2;
	int k, i = 0;
	char str[255];
	errno_t err, err1, err2, err3;
	err = fopen_s(&F1, "f1.txt", "w");
	if (err != 0) {
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < 6; i++)
	{
		printf("введите строку %d : \n", i + 1);
		gets_s(str);
		fputs(str, F1);
		fputs("\n", F1);
	}
	fclose(F1);
	err1 = fopen_s(&F1, "f1.txt", "r");
	err2 = fopen_s(&F2, "f2.txt", "w");

	for (int i = 0; i < 10 && fgets(str, 255, F1) != NULL; i++)
	{
		if (i % 2 != 0)
		{
			fputs(str, F2);
		}
	}

	fclose(F1);
	fclose(F2);
}
