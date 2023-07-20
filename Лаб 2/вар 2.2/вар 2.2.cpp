#include <stdio.h>

int main() {
	FILE* fa;
	FILE* fout;
	char name1[] = "f.txt";
	fopen_s(&fa, name1, "r");
	fopen_s(&fout, "g.txt", "w");


	int temp;
	int count = 0;
	int savePos[5];
	int saveNeg[5];
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
					savePos[count % 5] = temp;
				}
				else
					if (count / 5 == 3) {
						saveNeg[count % 5] = temp;
						if (count + 1 == 20) {
							for (int i = 0; i < 5; ++i)
								fprintf(fout, " %d\t", savePos[i]);
							fprintf(fout, "\n");
							for (int i = 0; i < 5; ++i)
								fprintf(fout, "%d\t", saveNeg[i]);
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