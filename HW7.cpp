#pragma warning(disable : 4996)
#include<stdio.h>

int main() {
	double dist, velo, sec;
	int hour, min;

	printf("* 거리를 입력하시오(km단위) : ");
	scanf("%lf", &dist);
	printf("* 시속을 입력하시오(km/h단위) : ");
	scanf("%lf", &velo);

	hour = (int)dist / velo;
	min = (int)((dist / velo - hour) * 60);
	sec = (dist/velo-hour-(double)min/60)*60*60;

	printf("%.2lf km = >%d시간 %d분 %.3lf 초 소요됨\n", dist, hour, min, sec);
	return 0;
}