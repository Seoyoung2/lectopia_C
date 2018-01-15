// 20180115 ÀÌ¼­¿µ
//move box ÇÁ·Î±×·¥

#pragma warning(disable : 4996)
#include <stdio.h>
#include <windows.h>
#include <conio.h>

void myflush(void);
void gotoxy(int x, int y);
void printBox(int sx, int ex, int sy, int ey);

int main() {
	int sx, sy, ex, ey;
	char ch;
	printf("sx ÁÂÇ¥ ÀÔ·Â(1~70) : ");
	scanf("%d", &sx);
	while (1) {
		printf("ex ÁÂÇ¥ ÀÔ·Â(%d~80) : ", sx + 1);
		scanf("%d", &ex);
		if (ex > sx && ex <= 80) { break; }
		myflush();
	}
	printf("sy ÁÂÇ¥ ÀÔ·Â(1~20) : ");
	scanf("%d", &sy);
	while (1) {
		printf("ey ÁÂÇ¥ ÀÔ·Â(%d~24) : ", sy + 1);
		scanf("%d", &ey);
		if (ey > sy && ey <= 80) { break; }
		myflush();
	}
	system("cls");
	printBox(sx, ex, sy, ey);

	while (1) {
		ch = getch();
		if (ch == 'w') {
			if (sy == 1) {
				sy = 24; ey--;
			}
			else if (ey == 1) {
				sy--; ey = 24;
			}
			else {
				sy--; ey--;
			}
			system("cls");
			printBox(sx, ex, sy, ey);
		}
		else if (ch == 'a') {
			if (sx == 1) {
				sx = 80; ex--;
			}
			else if (ex == 1) {
				ex = 80; sx--;
			}
			else {
				sx--; ex--;
			}
			system("cls");
			printBox(sx, ex, sy, ey);
		}
		else if (ch == 'd') {
			if (ex == 80) {
				ex = 1; sx++;
			}
			else if (sx == 80) {
				sx = 1; ex++;
			}
			else {
				sx++; ex++;
			}
			system("cls");
			printBox(sx, ex, sy, ey);
		}
		else if (ch == 's') {
			if (ey == 24) {
				sy++; ey = 1;
			}
			else if (sy == 24) {
				sy = 1; ey++;
			}
			else {
				sy++; ey++;
			}
			system("cls");
			printBox(sx, ex, sy, ey);
		}
		else if (ch == 27) {
			system("cls");
			return 0;
		}
		else { ; }
	}
	return 0;
}

void myflush(void) {
	while (getchar() != '\n');
	return;
}

void gotoxy(int x, int y) {
	COORD Pos = { (short)x - 1,(short)y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void printBox(int sx, int ex, int sy, int ey) {
	int i;
	gotoxy(sx, sy);
	if (sx > ex) {
		for (i = sx; i <= 80; i++) { printf("*"); }
		gotoxy(1, sy);
		for (i = 1; i <= ex; i++) { printf("*"); }
	}
	else {
		for (i = sx; i <= ex; i++) { printf("*"); }
	}
	gotoxy(sx, ey);
	if (sx > ex) {
		for (i = sx; i <= 80; i++) { printf("*"); }
		gotoxy(1, ey);
		for (i = 1; i <= ex; i++) { printf("*"); }
	}
	else {
		for (i = sx; i <= ex; i++) { printf("*"); }
	}
	gotoxy(sx, sy);
	if (sy > ey) {
		for (i = sy; i <= 24; i++) { gotoxy(sx, i); printf("*"); }
		for (i = 1; i <= ey; i++) { gotoxy(sx, i); printf("*"); }
	}
	else {
		for (i = sy; i <= ey; i++) { gotoxy(sx, i); printf("*"); }
	}
	gotoxy(ex, sy);
	if (sy > ey) {
		for (i = sy; i <= 24; i++) { gotoxy(ex, i); printf("*"); }
		for (i = 1; i <= ey; i++) { gotoxy(ex, i); printf("*"); }
	}
	else {
		for (i = sy; i <= ey; i++) { gotoxy(ex, i); printf("*"); }
	}
	return;
}