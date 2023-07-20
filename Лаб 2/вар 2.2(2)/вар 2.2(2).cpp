#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	FILE* fileA = fopen("f", "r");

	if (!fileA) {
		perror("f opening failed");
		return EXIT_FAILURE;
	}

	FILE* fileB = fopen("g", "w");
	if (!fileB) {
		perror("g opening failed");
		return EXIT_FAILURE;
	}

	int temp;
	int count = 0;
	int savePos[5];
	int saveNeg[5];
	while (fscanf(fileA, "%d", &temp) != EOF) {
		switch (count / 5) {
		case 0:
			fprintf(fileB, " %d\t", temp);
			if (count + 1 == 5)
				fprintf(fileB, "\n");
			break;
		case 2:
			fprintf(fileB, "%d\t", temp);
			if (count + 1 == 15)
				fprintf(fileB, "\n");
			break;
		case 1:
			savePos[count % 5] = temp;
			break;
		case 3:
			saveNeg[count % 5] = temp;
			if (count + 1 == 20) {
				for (int i = 0; i < 5; ++i)
					fprintf(fileB, " %d\t", savePos[i]);
				fprintf(fileB, "\n");
				for (int i = 0; i < 5; ++i)
					fprintf(fileB, "%d\t", saveNeg[i]);
				fprintf(fileB, "\n");

				count = 0;
				continue;
			}

		}
		++count;
	}

	fclose(fileA);
	fclose(fileB);

	return 0;
}
