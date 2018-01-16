//180116 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

int inputCnt(void);
void inputNum(int *, int);
int checkNum(int *, int);

int main() {
	int count, diff;
	int num[1000];
	while (1) {
		count = inputCnt();
		if (count == -1) { return 0; }
		inputNum(num, count);
		diff = checkNum(num, count);
		printf("���� �ٸ� ���� ���� : %d\n\n", diff);
	}
}

int inputCnt(void) {
	int count, res;
	while (1) {
		printf("* �Է��� ������ ���� : ");
		res = scanf("%d", &count);
		if (count >= 2 && count <= 1000) { break; }
		else if (res != 1) { return -1; }
	}
	return count;
}

void inputNum(int *num, int count) {
	int i;
	printf("* ���� �Է� : ");
	for (i = 0; i < count; i++) {
		scanf(" %d", &num[i]);
	}
}

int checkNum(int *num, int count) {
	int diff=1, tmp, i,j;
	for (i = 1; i <= count-1; i++) {
		tmp = 0;
		for (j = 0; j < i; j++) {
			if (num[i] == num[j]) { 
				tmp = 1;
				break; 
			}
		}
		if (tmp == 1) { continue; }
		 diff++;
	}
	return diff;
}