// 180105 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

int main() {
	int i, j;
	char big;

	while (1) {
		printf("* ������ �빮�� �Է�('A'~'Z') : ");
		scanf("%c", &big);
		getchar();
		if (big<'A' || big>'Z') {
			break;
		}
		for (i = 0; i <= big - 'A'; i++) {
			for (j = big ; j >= big-i; j--) {
				printf("%c", j);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
