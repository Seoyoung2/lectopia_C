//180119 이서영
// Jolly jumper

#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>

int inputArr(FILE*, int*);
int calJolly(int *, int);
void output(int, int *, int);

int main() {
	int dataCnt, testCnt, i, res;
	int arr[100];
	FILE *fp;
	fp = fopen("C:\\data\\hw63_jolly.txt", "rt");
	if (fp == NULL) {
		printf("File open error!\n");
		return 0;
	}
	fscanf(fp, "%d", &testCnt);
	for (i = 0; i < testCnt; i++) {
		dataCnt = inputArr(fp, arr);
		res = calJolly(arr, dataCnt);
		output(dataCnt, arr, res);
	}
	return 0;
}

int inputArr(FILE *fp, int *arr) {
	int dataCnt, i;
	fscanf(fp, "%d", &dataCnt);
	for (i = 0; i < dataCnt; i++) {
		fscanf(fp, "%d", arr + i);
	}
	return dataCnt;
}

int calJolly(int *arr, int dataCnt) {
	int gap[100];
	int i,j, temp, res=1;
	for (i = 0; i < dataCnt-1; i++) {
		gap[i] = abs(arr[i + 1] - arr[i]);
	}
	for (i = 0; i < dataCnt-1; i++) {
		for (j = i + 1; j < dataCnt-1; j++) {
			if (gap[i] > gap[j]) {
				temp = gap[i];
				gap[i] = gap[j];
				gap[j] = temp;
			}
		}
	}
	for (i = 0; i < dataCnt - 2; i++) {
		if (gap[i + 1] - gap[i] != 1) { res = 0; break; }
	}
	return res;
}

void output(int dataCnt, int *arr, int res) {
	int i;
	printf("검사한 수열 : ");
	for (i = 0; i < dataCnt; i++) {
		printf("%d ", arr[i]);
	}
	if (res == 1) {
		printf("(Jolly jumper)\n");
	}
	else {
		printf("(Not jolly jumper)\n");
	}
	return;
}