// 180117 이서영
// 똬리 배열

#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>

int inputNum(void);
void inputArr(int(*)[100], int);
void output(int(*)[100], int);

int main() {
	int arr[100][100];
	int num;

	num = inputNum();
	inputArr(arr, num);
	output(arr, num);

	return 0;
}

int inputNum(void) {
	int num;
	while (1) {
		printf("# 행/열의 수 입력 : ");
		scanf("%d", &num);
		if (num > 0 && num <= 100) {
			if (getchar() == '\n') { break; }
		}
		while (getchar() != '\n');
	}
	return num;
}

void inputArr(int(*arr)[100], int num) {
	int i, row=0, col=0, val=1, temp;
	temp = num;
	while (1) {
		for (i = 0; i < temp; i++) {
			arr[row][col++] = val;
			val++;
			if (val == (pow(num,2) + 1)) {
				return;
			}
		}
		col--;
		for (i = 0; i < temp - 1; i++) {
			arr[++row][col] = val;
			val++;
			if (val == (pow(num, 2) + 1)) {
				return;
			}
		}
		for (i = 0; i < temp - 1; i++) {
			arr[row][--col] = val;
			val++;
			if (val == (pow(num, 2) + 1)) {
				return;
			}
		}
		for (i = 0; i < temp - 2; i++) {
			arr[--row][col] = val;
			val++;
			if (val == (pow(num, 2) + 1)) {
				return;
			}
		}
		temp -= 2;
		col++;
	}
	
}

void output(int(*arr)[100], int num) {
	int i, j;
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			printf("%6d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}