// 180105 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

int main() {
	int num, i=1, sum=0;

	for (i = 1; i <= 5; ) {
		printf("0���� ū���� �Է��Ͻÿ�(%d ��°) : ", i);
		scanf("%d", &num);
		if (num > 0) {
			sum += num;
			i++;
		}
	}
	printf("�Էµ� ���� �� �� : %d\n", sum);
	return 0;
}