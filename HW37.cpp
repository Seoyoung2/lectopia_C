//180112 이서영

#pragma warning(disable : 4996)
#include <stdio.h>

void myflush(void);

int main() {
	int day, money=0,i, j,k=0;
	int arr[100];
	while (1) {
		printf("* 기사의 근무일수를 입력하시오 : ");
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
	printf("  근무일 : %d 일 / 총 금화 수 : %d 개\n", day, money);
	return 0;
}
void myflush(void) {
	while (getchar() != '\n');
	return;
}
