//180112 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

void myflush(void);

int main() {
	int day, money=0,i, j,k=0;
	int arr[100];
	while (1) {
		printf("* ����� �ٹ��ϼ��� �Է��Ͻÿ� : ");
		scanf("%d", &day);
		if (getchar() == '\n') { break; }
		myflush();
	}
	for (i = 0; k < day; i++) {
		for (j = 0; j < i; j++) {
			if (k == day) { break; }
			arr[k] = i;
			money += arr[k++];
		}
	}
	printf("  �ٹ��� : %d �� / �� ��ȭ �� : %d ��\n", day, money);
	return 0;
}
void myflush(void) {
	while (getchar() != '\n');
	return;
}
