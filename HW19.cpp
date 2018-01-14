//180102 이서영

#include<stdio.h>
#pragma warning(disable : 4996)

int inputYear(void);
int yearCheck(int year);

int main()
{
	int year, res;
	year = inputYear();
	res = yearCheck(year);

	if (res == 1) {
		printf("%d년은 윤년(Leap year)입니다.\n", year);
	}
	else {
		printf("%d년은 평년(Common year)입니다.\n", year);
	}
	return 0;
}

int inputYear(void) {
	int year;
	printf("년도를 입력하시오 : ");
	scanf("%d", &year);
	return year;
}

int yearCheck(int year) {
	if (year % 4 != 0) {
		return 0;
	}
	else {
		if (year % 100 != 0) {
			return 1;
		}
		else {
			if (year % 400 == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
}