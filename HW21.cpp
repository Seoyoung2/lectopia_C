//180102 �̼���

#include<stdio.h>
#pragma warning(disable : 4996)

int main()
{
	double height, sum=0;
	int i = 1;

	while (i <= 5) {
		printf("- %d�� �л��� Ű��? ", i++);
		scanf("%lf", &height);
		sum += height;
	}
	printf("�ټ� ���� ��� Ű�� %.1lf cm �Դϴ�.\n", sum/5);
	return 0;
}