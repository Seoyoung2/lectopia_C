// 20180115 이서영
//정수 값 소트 프로그램 (1차원 배열사용)

#pragma warning(disable : 4996)
#include <stdio.h>

int fileRead(FILE *, int *);
void sort(int*, int);
void output(char*, int *, int);

int main() {
	int testCnt, dataCnt, i;
	int dataArray[30];
	FILE *fp;

	if ((fp = fopen("C:\\data\\hw52_sortData.txt", "rt")) == NULL) {
		printf("File open error!\n");
	}
	fscanf(fp, "%d", &testCnt);
	for (i = 0; i < testCnt; i++) {
		dataCnt = fileRead(fp, dataArray);
		output("# 소트 전 데이터 :", dataArray, dataCnt);
		sort(dataArray, dataCnt);
		output("# 소트 후 데이터 :", dataArray, dataCnt);
		printf("\n");
	}
	fclose(fp);
	return 0;
}

int fileRead(FILE *fp, int *dataArray) {
	int dataCnt = 0;
	while (1) {
		fscanf(fp, "%d", &dataArray[dataCnt]);
		if (dataArray[dataCnt] == 0) break;
		dataCnt++;
	}
	return dataCnt;
}

void sort(int *dataArray, int dataCnt) {
	int i, j, tmp;
	for (i = 0; i < dataCnt; i++) {
		for (j = i+1; j < dataCnt; j++) {
			if (dataArray[i] > dataArray[j]) {
				tmp = dataArray[i];
				dataArray[i] = dataArray[j];
				dataArray[j] = tmp;
			}
		}
	}
	return;
}

void output(char *str, int *dataArray, int dataCnt) {
	int i;
	printf("%s", str);
	for (i = 0; i < dataCnt; i++) {
		printf("%4d", dataArray[i]);
	}
	printf("\n");
	return;
}