// 180105 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

int main() {
	int i, j, k;

	printf("<2�� for���� �̿��� ���>\n");
	for (i = 1; i <= 9; i++) {
		for (j = 2; j <= 5; j++) {
			printf("%d*%d = %2d\t", j, i, j*i);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 1; i <= 9; i++) {
		for (j = 6; j <= 9; j++) {
			printf("%d*%d = %2d\t", j, i, j*i);
		}
		printf("\n");
	}
	printf("---------------------------------------------------------\n\n");
	printf("<3�� for���� �̿��� ���>\n");
	for (k = 0; k < 5; k+=4) {
		for (i = 1; i <= 9; i++) {
			for (j = 2; j <= 5; j++) {
				printf("%d*%d = %2d\t", j+k, i, (j+k)*i);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}