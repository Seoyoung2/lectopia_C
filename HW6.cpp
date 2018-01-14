#pragma warning(disable : 4996)
#include<stdio.h>

int input(void);
void output(double temp);

int main() {
	int ftemp;
	double ctemp;

	ftemp = input();
	ctemp = (double)5 / 9 * (ftemp - 32);
	output(ctemp);

	return 0;
}

int input(void) {
	int ftemp;
	printf("화씨 온도를 입력하세요 : ");
	scanf("%d", &ftemp);
	return ftemp;
}

void output(double temp) {
	printf("섭씨 온도는 %.1lf도입니다.\n", temp);
	return;
}