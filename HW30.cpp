//180109 �̼���

#pragma warning(disable : 4996)
#include<stdio.h>

int main() {
	int num, res=0x80000000;
	while (1) {
		printf("* 10���� ������ �Է��Ͻÿ� : ");
		scanf("%d", &num);
		if (getchar() == '\n') { break; }
		while (getchar() != '\n');

	}
	
	printf("%d(10) = ", num);
	while (num!=0) {
		if ((num&res) == 0) {
			printf("0");
		}
		else {
			printf("1");
		}
		num <<= 1;
	}
	printf("(2)\n");
	return 0;
}