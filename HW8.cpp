#pragma warning(disable : 4996)
#include<stdio.h>

int main()
{
	int his, kor, ent, sum;
	double mean;

	printf("����, ����, ���� ������ �Է��ϼ��� : ");
	scanf("%d %d %d", &his, &kor, &ent);

	sum = his + kor + ent;
	mean = (double)sum / 3;
	printf("������ %d �̰� ����� %.2lf �Դϴ�.\n", sum, mean);
	
	return 0;
}