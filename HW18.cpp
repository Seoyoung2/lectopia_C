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
	printf("���尴�� ���̸� �Է��Ͻÿ� : ");
	scanf("%d", &age);
	return age;
}

int inputnum(void) {
	int num;
	printf("���尴�� ���� �Է��Ͻÿ� : ");
	scanf("%d", &num);
	return num;
}

void output(int money, int sale) {
	printf("\n");
	printf("����� => %d��\n", money);
	printf("���αݾ� => %d��\n", sale);
	printf("�����ݾ� => %d��\n", money-sale);
	return;
}