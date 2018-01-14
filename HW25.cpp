//180108 이서영

#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputInt(void);
int output(int, int, int, int);
void myflush(void);

int main() {
	int randnum, num, res;
	int min=0, max=101, count=0;
	srand((unsigned int)time(NULL));
	randnum = rand() % 100 +1;
	
	while (1) {
		num = inputInt();
		++count;
		res = output(randnum, num, min, max);
		if (res == 1) {
			max = num;
		}
		else if (res == -1) {
			min = num;
		}
		else {
			printf("우와~ 맞았당~~~ 추카추카~~ %d 번째 만에 맞추셨습니다.\n", count);
			break;
		}
	}
	return 0;
}

int inputInt(void) {
	int num;
	while (1) {
		printf("# 숫자를 입력하시오 : ");
		scanf("%d", &num);
		if (getchar() != '\n') {
			myflush();
			continue;
		}
		if (num >= 1 && num <= 100) { break; }
	}
	return num;
}

void myflush(void) {
	while (getchar() != '\n');
	return;
}

int output(int randnum, int num, int min, int max) {
	int res;
	if (num > randnum) {
		printf("%d보다는 크고 %d보다는 작습니다.\n", min, num);
		res = 1;
	}
	else if (num < randnum) {
		printf("%d보다는 크고 %d보다는 작습니다.\n", num, max);
		res = -1;
	}
	else {
		res = 0;
	}
	return res;
}