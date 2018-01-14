//180102 �̼���

#include<stdio.h>
#pragma warning(disable : 4996)

int inputTime(void);
int calSum(int time);
int calTax(int time);
void output(int sum, int tax);

int main()
{
	int time, sum, tax;
	time = inputTime();
	sum = calSum(time);
	tax = calTax(sum);
	output(sum, tax);
	return 0;
}

int inputTime(void) {
	int time;
	printf("* 1���ϰ��� �ٹ��ð��� �Է��Ͻÿ� :");
	scanf("%d", &time);
	return time;
}

int calSum(int time) {
	int sum;
	if (time <= 40) {
		sum = time * 3000;
	}
	else {
		sum = 40 * 3000 + (time - 40) * 3000 * 1.5;
	}
	return sum;
}

int calTax(int sum) {
	int tax;
	if (sum <= 100000) {
		tax = sum * 0.15;
	}
	else {
		tax = 100000 * 0.15 + (sum - 100000)*0.25;
	}
	return tax;
}

void output(int sum, int tax) {
	printf("# �Ѽ��� : %6d��\n", sum);
	printf("# ��  �� : %6d��\n", tax);
	printf("# �Ǽ��� : %6d��\n", sum-tax);
	return;
}