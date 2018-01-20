//180119 이서영
// 년월변경 달력 프로그램

#pragma warning(disable : 4996)
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define BLACK 0
#define LIGHTGRAY 7
#define LIGHTBLUE 9 
#define LIGHTRED 12

int calDate(int , int);
void printDate(int year, int month);
int yearCheck(int year);

int main() {
	int year = 2018, month = 1;
	char ch;
	
	printDate(year, month);
	while (1) {
		ch = getch();
		if (ch == 'w') {
			year--;
			printDate(year, month);
		}
		else if (ch == 's') {
			year++;
			printDate(year, month);
		}
		else if (ch == 'a') {
			if (month == 1) {
				year--;
				month = 13;
			}
			month--;
			printDate(year, month);
		}
		else if (ch == 'd') {
			if (month == 12) {
				year++;
				month = 0;
			}
			month++;
			printDate(year, month);
		}
		else if (ch == 27) {
			system("cls");
			return 0;
		}
	}
	return 0;
}

int calDate(int year, int month) {
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
	return (sum+1);
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
void textcolor(int foreground, int background) {
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y) {
	COORD Pos = { (short)x - 1,(short)y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void printDate(int year, int month) {
	int week, day=1, cnt=7, i;
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (yearCheck(year) == 1) {
		mon[1] = 29;
	}
	system("cls");
	gotoxy(32, 2);
	textcolor(LIGHTGRAY, BLACK);
	printf("[ %d .  %d ]", year, month);
	gotoxy(20, 4);
	printf("  SUN  MON  TUE  WED  THU  FRI  SAT");
	gotoxy(20, 5);
	printf("-------------------------------------");
	gotoxy(20, 6);

	week = calDate(year, month) % 7;
	for (i = 0; i < week; i++) {
		printf("     ");
	}
	while (1) {
		if (day == mon[month-1]+1) { break; }
		if (week == 7) { week = 0; }
		if (week == 0) {
			textcolor(LIGHTRED, BLACK);
			printf("%5d", day++);
			week++;
		}
		else if (week == 6) {
			textcolor(LIGHTBLUE, BLACK);
			printf("%5d", day++);
			gotoxy(20, cnt++);
			week++;
		}
		else { 
			textcolor(LIGHTGRAY, BLACK);
			printf("%5d", day++); 
			week++;
		}
	}
	gotoxy(6, 13);
	textcolor(LIGHTGRAY, BLACK);
	printf("w : 전 년도 / s : 다음 년도 / a : 전 월 / d : 다음 월 / ESC : 종료\n");
	return;
}