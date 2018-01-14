//180112 이서영

#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initArr(int(*)[4]);
void printArr(int(*)[4]);

int main() {
	int num[3][4];
	srand((unsigned int)time(NULL));

	initArr(num);
	printArr(num);
	return 0;
}

void initArr(int(*num)[4]) {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			num[i][j] = rand() % 9 + 1;
		}
	}
}
void printArr(int(*num)[4]) {
	int sum = 0, i, j;
	for (i = 0; i < 3; i++) {
		printf("%d행     :", i);
		for (j = 0; j < 4; j++) {
			printf("%4d", num[i][j]);
			sum += num[i][j];
		}
		printf("     %d행의 합 : %d\n", i, sum);
		sum = 0;
	}
	printf("열의 합 :");
	for (i = 0; i < 4; i++) {
		sum = 0;
		for (j = 0; j < 3; j++) {
			sum += num[j][i];
		}
		printf("%4d", sum);
	}
	printf("\n");
	return;
}