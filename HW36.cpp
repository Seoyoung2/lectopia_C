// 180105 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

int main() {
	int i, num, sum=0;
	int tmp, n1 = 1, n2 = 1;
	printf("�Ǻ���ġ ������ �׼��� �Է��Ͻÿ� : ");
	scanf("%d", &num);

	printf("1 + 1 + ");
	for (i = 3; i <= num; i++) {
		tmp = n1 + n2;
		sum += tmp;
		n1 = n2;
		n2 = tmp;
		printf("%d + ", tmp);
	}
	printf("\b\b= %d\n", sum+2);
	return 0;
}