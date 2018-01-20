//180119 이서영
// 야구게임 만들기

#pragma warning(disable : 4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <process.h>

void makeRan(int *);
void matchRan(int *);

int main() {
	int i, j=1;
	int num[4];
	srand((unsigned int)time(NULL));
	makeRan(num);
	for (i = 0; i < 4; i++) {
		printf("%3d", num[i]);
	}
	printf("\n\n");
	while (1) {
		printf("# %d차 : ", j);
		matchRan(num);
		j++;
	}
	return 0;
}

void makeRan(int *num) {
	int i, count=0, r;
	while (1) {
		if (count == 5) { break; }
		r = rand() % 10;
		for (i = 0; i < count; i++) {
			if (r == num[i]) { break; }
		}
		if (r != num[i]) {
			num[count++] = r;
		}
	}
	return;
}

void matchRan(int *num) {
	int i,j, my[4];
	int ball = 0, strike = 0;
	for (i = 0; i < 4; i++) {
		scanf("%d", my + i);
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (my[i] == num[j]) {
				if (i == j) { strike++; break; }
				ball++;
				break;
			}
		}
	}
	if (strike == 4) {
		printf("\t\tOK!!!\n");
		exit(0);
	}
	else if (strike == 0 && ball == 0) {
		printf("\t\tNO!\n");
		return;
	}
	printf("\t\t%dS %dB\n", strike, ball);
	return;
}