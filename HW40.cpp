// 180105 이서영

#pragma warning(disable : 4996)
#include <stdio.h>

int main() {
	int line, i, j;
	while (1) {
		printf("# 출력 라인수를 입력하시오 : ");
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