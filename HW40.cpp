// 180105 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

int main() {
	int line, i, j;
	while (1) {
		printf("# ��� ���μ��� �Է��Ͻÿ� : ");
		scanf("%d", &line);
		if (getchar() != '\n') { break; }
		for (i = 1; i <= line; i++) {
			for (j = 1; j <= i; j++) {
				printf("*");
			}
			for (j = 2 * (line - i) + 3; j >= 1; j--) {
				printf(" ");
			}
			for (j = 1; j <= i; j++) {
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}