//180116 이서영
//히스토그램을 출력하기 프로그램

#pragma warning(disable : 4996)
#include <stdio.h>

int inputArr(FILE*, int*);
void output(int *, int);

int main(void) {
	int data[30] = { 0 };
	int testCnt, dataCnt, i;
	FILE *fp;
	fp = fopen("C:\\data\\hw58_histogram.txt", "rt");
	if (fp == NULL) {
		printf("File open error!\n");
	}
	fscanf(fp, "%d", &testCnt);
	for (i = 0; i < testCnt; i++) {
		dataCnt = inputArr(fp, data);
		output(data, dataCnt);
	}
	return 0;
}

int inputArr(FILE *fp, int *data) {
	int dataCnt = 0;
	while (1) {
		fscanf(fp, "%d", &data[dataCnt]);
		if (data[dataCnt] == 0) { break; }
		dataCnt++;
	}
	return dataCnt;
}

void output(int *data, int dataCnt) {
	char histo[30][9] = { 0 };
	int i, j;
	for (i = 0; i < dataCnt; i++) {
		for (j = 0; j < data[i]; j++) {
			histo[i][j] = '*';
		}
	}
	for (j = 8; j >= 0; j--) {
		for (i = 0; i < 30; i++) {
			if (histo[i][j] == 0) { printf(" "); continue; }
			printf("%c", histo[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < dataCnt; i++) {
		printf("%d", data[i]);
	}
	printf("\n------------------------------\n");
	return;
}