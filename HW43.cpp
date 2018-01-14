//180112 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>

int input(char *);
int primeNumber(int);

int main() {
	int i,count=0, num, res;
	num = input("* ������ �ϳ��� �Է��Ͻÿ� : ");
	printf("1~%d������ �Ҽ� ���� ������ �����ϴ�.\n", num);
	for (i = 2; i < num; i++) {
		res = primeNumber(i);
		if (res == 1) {
			printf("%-5d", i);
			count++;
			if (count % 5 == 0) {
				printf("\n");
			}
		}
	}
	printf("\n1~%d������ �� ���Ҵ� %d�� �Դϴ�.\n", num, count);
	return 0;
}

int input(char *str) {
	int res, num;
	while (1) {
		printf("%s", str);
		res = scanf("%d", &num);
		if (getchar() != '\n') {
			while (getchar() != '\n');
			continue;
		}
		if (res == 1) {
			if (num > 0) { break; }
		}
		else { ; }
	}
	return num;
}
int primeNumber(int number) {
	int res=1, i;
	for (i = 2; i <= (int)sqrt((double)number); i++) {
		if (number%i == 0) {
			res = 0;
			break;
		}
	}
	return res;
}