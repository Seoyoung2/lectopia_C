#include<stdio.h>

int main()
{
	double year = 365.2422;
	int day, hour, min;
	double sec;

	day = (int)year;
	hour = (int)((year - day) * 24);
	min = (int)((year-day-(double)hour/24)*24*60);
	sec = (year - day - (double)hour / 24 - (double)min / 24 / 60) * 24 * 60 * 60;

	printf("%.4lf일은 %d일 %d시간 %d분 %.2lf초입니다. \n", year, day, hour, min, sec);
	return 0;
}