//180108 이서영

#pragma warning(disable : 4996)
#include <stdio.h>

int inputInt(void);

int main() {
	int weight, count=0;

	while (1) {
		weight = inputInt();
		if (weight < 150) {
			printf("* 메추리알 가지고 장난하지 마시오~ ^^\n");
		}
		else if (weight > 500) {
			printf("* 타조알 가지고 장난하지 마시오~ ^^\n");
		}
		else {
			printf("* 현재 달걀의 수 : %d\n", ++count);
		}
		if (count == 10) {break;}
	}
	printf("\n*** 달걀 포장이 끝났습니다.\n");
	return 0;
}

int inputInt(void) {
	int weight;
	while (1) {
		printf("# 계란의 무게를 입력하세요(단위 : g) : ");
		scanf("%d", &weight);
		if (getchar() == '\n') {break;}
		while (getchar() != '\n');
	}
	return weight;
}