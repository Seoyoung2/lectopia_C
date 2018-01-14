#pragma warning(disable : 4996)
#include <stdio.h>

int inputage(void);
int inputnum(void);
void output(int money, int sale);

int main() {
	int age, num, money, sale=0;

	age = inputage();
	num = inputnum();
	
	if (age<=7) {
		money = 500*num;
	}
	else if (age <= 13) {
		money = 700 * num;
	}
	else if (age <= 19) {
		money = 1000 * num;
	}
	else if (age <= 55) {
		money = 1500 * num;
	}
	else {
		money = 500 * num;
	}

	if (num >= 5) {
		sale = money*10/100;
	}
	output(money, sale);
	return 0;
}

int inputage(void) {
	int age;
	printf("입장객의 나이를 입력하시오 : ");
	scanf("%d", &age);
	return age;
}

int inputnum(void) {
	int num;
	printf("입장객의 수를 입력하시오 : ");
	scanf("%d", &num);
	return num;
}

void output(int money, int sale) {
	printf("\n");
	printf("입장료 => %d원\n", money);
	printf("할인금액 => %d원\n", sale);
	printf("결제금액 => %d원\n", money-sale);
	return;
}