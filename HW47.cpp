// 180111 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

void inputInt(double *);
double calMax(double *);
double calMin(double *);
void output(double, double);
void myflush(void);

int main() {
	double arr[5];
	double max, min;

	inputInt(arr);
	max = calMax(arr);
	min = calMin(arr);
	output(max, min);

	return 0;
}

void myflush(void) {
	while (getchar() != '\n');
	return;
}

void inputInt(double *p) {
	int i;
	for (i = 0; i < 5; i++) {
		while (1) {
			printf("%d �� �� �� : ", i);
			scanf("%lf", &p[i]);
			if (getchar() == '\n') { break; }
			else { myflush(); }
		}
	}
	return;
}
double calMax(double *p) {
	int i; 
	double max = p[0];
	for (i = 1; i <  5; i++) {
		if (max < p[i]) {
			max = p[i];
		}
	}
	return max;
}
double calMin(double *p) {
	int i;
	double min = p[0];
	for (i = 1; i < 5; i++) {
		if (min > p[i]) {
			min = p[i];
		}
	}
	return min;
}
void output(double max, double min) {
	printf("\n���� ū �� : %.2lf\n", max);
	printf("���� ���� �� : %.2lf\n", min);
	return;
}