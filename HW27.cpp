//180108 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

int inputInt(void);

int main() {
	int weight, count=0;

	while (1) {
		weight = inputInt();
		if (weight < 150) {
			printf("* ���߸��� ������ �峭���� ���ÿ�~ ^^\n");
		}
		else if (weight > 500) {
			printf("* Ÿ���� ������ �峭���� ���ÿ�~ ^^\n");
		}
		else {
			printf("* ���� �ް��� �� : %d\n", ++count);
		}
		if (count == 10) {break;}
	}
	printf("\n*** �ް� ������ �������ϴ�.\n");
	return 0;
}

int inputInt(void) {
	int weight;
	while (1) {
		printf("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
		scanf("%d", &weight);
		if (getchar() == '\n') {break;}
		while (getchar() != '\n');
	}
	return weight;
}