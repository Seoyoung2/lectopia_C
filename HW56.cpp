//180112 이서영

#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initArr(int(*)[5]);
void calArr(int(*)[5], int*);
void printArr(int(*)[5], int*);

int main() {
	int arr[5][5];
	int sum[3] = { 0 };
	srand((unsigned int)time(NULL));

	initArr(arr);
	calArr(arr, sum);
	printArr(arr, sum);
	return 0;
}

void initArr(int(*arr)[5]) {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			arr[i][j] = rand() % 20 + 1;
		}
	}
	return;
}

void calArr(int(*arr)[5], int *sum) {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (i > j) {
				sum[2] += arr[i][j];
			}
			else if (i < j) {
				sum[1] += arr[i][j];
			}
			else {
				sum[0] += arr[i][j];
			}
		}
	}
	return;
}

void printArr(int(*arr)[5], int *sum) {
	int i, j;
	for (i = 0; i < 5; i++) {
		printf("%d번 행 :", i);
		for (j = 0; j < 5; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < 3; i++) {
		printf("sum%d = %d\n", i + 1, sum[i]);
	}
	return;
}