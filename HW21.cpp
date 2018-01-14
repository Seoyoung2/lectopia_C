//180102 이서영

#include<stdio.h>
#pragma warning(disable : 4996)

int main()
{
	double height, sum=0;
	int i = 1;

	while (i <= 5) {
		printf("- %d번 학생의 키는? ", i++);
		scanf("%lf", &height);
		sum += height;
	}
	printf("다섯 명의 평균 키는 %.1lf cm 입니다.\n", sum/5);
	return 0;
}