//180102 이서영

#include<stdio.h>
#pragma warning(disable : 4996)

int input(void);

int main() {
	int num, i=0;
	num = input();

	while (i<num) {
		printf("*");
		i++;
		if (i % 5 == 0) {
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}

int input(void) {
	int num;
	printf("# 정수값을 입력하세요 : ");
	scanf("%d", &num);
	return num;
}