//180112 이서영

#pragma warning(disable : 4996)
#include <stdio.h>

int input(void);
int checkValue(int, int, int);
int calSum(int, int, int);
void output(int, int, int, int);
int yearCheck(int);

int main() {
	int year, month, day, sum;
	while (1) {
		printf("* 년 월 일을 입력하시오 : ");
		year = input();
		month = input();
		day = input();
		if (year == -1 || month == -1 || day == -1) { return 0; }
		if (checkValue(year, month, day) == 1) { break; }
	}
	sum = calSum(year, month, day);
	output(year, month, day, sum);
	return 0;
}

int input(void) {
	int num, res;
	res = scanf("%d", &num);
	if (res!=1) { return -1; }
	return num;
}

int checkValue(int year, int month, int day) {
	int res=0;
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year >= 1900) {
		if (month >= 1 && month <= 12) {
			if (month==2){
				if (yearCheck(year) == 0) {
					if (day >= 1 && day <= 28) { res = 1; }
					else { res = 0; }
				}
				else {
					if(day >= 1 && day <= 29) { res = 1; }
					else { res = 0; }
				}
			}
			else if (day >= 1 && day <= mon[month - 1]) { res = 1; }
			else { res = 0; }
		}
		else { res = 0; }
	}
	else { res = 0; }
	return res;
}
int calSum(int year, int month, int day) {
	int i, sum = 0;
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (yearCheck(year) == 1) {
		mon[1] = 29;
	}
	for (i = 1900; i < year; i++) {
		if (yearCheck(i) == 1) {
			sum += 366;
		}
		else {
			sum += 365;
		}
	}
	for (i = 0; i < month - 1; i++) {
		sum += mon[i];
	}
	sum += day;
	return sum;
}

void output(int year, int month, int day, int sum) {
	char *week = 0;
	switch (sum % 7) {
	case 0: week = "일요일"; break;
	case 1: week = "월요일"; break;
	case 2: week = "화요일"; break;
	case 3: week = "수요일"; break;
	case 4: week = "목요일"; break;
	case 5: week = "금요일"; break;
	case 6: week = "토요일"; break;
	default: break;
	}
	printf("  %d년 %d월 %d일은 %s입니다.\n", year, month, day, week);
	return;
}

int yearCheck(int year) {	//1이면 윤년(29일-366일), 0이면 평년(28일-365일)
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