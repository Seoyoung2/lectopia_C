#include<stdio.h>
#pragma warning(disable : 4996)

int input(void);
void output(double sum);

int main() {
	int elec;
	double sum;

	elec = input();
	sum = (660 + (elec*88.5)) * 109 / 100;
	output(sum);

	return 0;
}

int input(void) {
	int a;
	printf("전기 사용량을 입력하세요(kw) : ");
	scanf("%d", &a);
	return a;
}

void output(double sum) {
	printf("전기 사용요금은 %lf 원 입니다.\n", sum);
	return;
}