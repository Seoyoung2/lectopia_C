#pragma warning(disable : 4996)
#include<stdio.h>

int main() {
	double dist, velo, sec;
	int hour, min;

	printf("* �Ÿ��� �Է��Ͻÿ�(km����) : ");
	scanf("%lf", &dist);
	printf("* �ü��� �Է��Ͻÿ�(km/h����) : ");
	scanf("%lf", &velo);

	hour = (int)dist / velo;
	min = (int)((dist / velo - hour) * 60);
	sec = (dist/velo-hour-(double)min/60)*60*60;

	printf("%.2lf km = >%d�ð� %d�� %.3lf �� �ҿ��\n", dist, hour, min, sec);
	return 0;
}