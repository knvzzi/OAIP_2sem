#include <stdio.h>

int main() {
	FILE* fa;
	FILE* fout;
	char name1[] = "file1.txt";
	fopen_s(&fa, name1, "r");
	fopen_s(&fout, "file2.txt", "w");


	int temp;
	int count = 0;
	int Pos[5];
	int Neg[5];
	while (fscanf_s(fa, "%d", &temp) != EOF) {
		if (count / 5 == 0) {
			fprintf(fout, " %d\t", temp);
			if (count + 1 == 5)
				fprintf(fout, "\n");
		}
		else
			if (count / 5 == 2) {
				fprintf(fout, "%d\t", temp);
				if (count + 1 == 15)
					fprintf(fout, "\n");
			}
			else
				if (count / 5 == 1) {
					Pos[count % 5] = temp;
				}
				else
					if (count / 5 == 3) {
						Neg[count % 5] = temp;
						if (count + 1 == 20) {
							for (int i = 0; i < 5; ++i)
								fprintf(fout, " %d\t", Pos[i]);
							fprintf(fout, "\n");
							for (int i = 0; i < 5; ++i)
								fprintf(fout, "%d\t", Neg[i]);
							fprintf(fout, "\n");

							count = 0;
						}
					}
		++count;
	}



	fclose(fa);
	fclose(fout);
	return 0;
}
