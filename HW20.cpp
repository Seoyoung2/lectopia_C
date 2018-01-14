//180102 이서영

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
	printf("* 1주일간의 근무시간을 입력하시오 :");
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
	printf("# 총수입 : %6d원\n", sum);
	printf("# 세  금 : %6d원\n", tax);
	printf("# 실수입 : %6d원\n", sum-tax);
	return;
}