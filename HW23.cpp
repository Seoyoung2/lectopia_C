// 180104 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

int main(void)
{
	int a, b, res;

	while (1) {
		printf("# �ΰ��� ������ �Է��ϼ��� : ");
		res = scanf("%d %d", &a, &b);
		if (res == 2) {
			if (a > b) {
				printf("%d - %d = %d\n", a, b, a - b);
			}
			else {
				printf("%d - %d = %d\n", b, a, b - a);
			}
		}
		else {
			break;
		}
	}
	return 0;
}