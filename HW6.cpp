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
	printf("ȭ�� �µ��� �Է��ϼ��� : ");
	scanf("%d", &ftemp);
	return ftemp;
}

void output(double temp) {
	printf("���� �µ��� %.1lf���Դϴ�.\n", temp);
	return;
}