#pragma warning(disable : 4996)
#include <stdio.h>

int input(void);
int cal(int);
void output(int);

int main()
{
	int station, price;
	station = input();
	price = cal(station);
	output(price);

	return 0;
}

int input(void) {
	int n;
	printf("������ �Է��Ͻÿ� :");
	scanf("%d", &n);
	return n;
}

int cal(int sta) {	//��� ��� �Լ�
	int pri, a;
	if (sta <= 5) {
		pri = 600;
	}
	else if (sta <= 10) {
		pri = 800;
	}
	else {
		a = sta - 10;
		pri = 800 + a / 4 * 200;
		if (a - a / 4 *4== 3) {
			pri += 200;
		}
		else if (a - a / 4 *4== 1|| a - a / 4 * 4 == 2) {
			pri += 100;
		}
	}
	return pri;
}

void output(int m) {
	printf("��� : %d��\n", m);
	return;
}