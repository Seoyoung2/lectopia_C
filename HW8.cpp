#pragma warning(disable : 4996)
#include<stdio.h>

int main()
{
	int his, kor, ent, sum;
	double mean;

	printf("역사, 문학, 예능 점수를 입력하세요 : ");
	scanf("%d %d %d", &his, &kor, &ent);

	sum = his + kor + ent;
	mean = (double)sum / 3;
	printf("총점은 %d 이고 평균은 %.2lf 입니다.\n", sum, mean);
	
	return 0;
}