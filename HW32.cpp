//180109 이서영

#pragma warning(disable : 4996)
#include<stdio.h>

int inputUInt(char*);
double inputDouble(char*);
int ipow(int, int);
double fpow(double, int);
void myflush(void);

int main() {
	int down, up, fup, res;
	double fdown, fres;

	down = inputUInt("* 양의 정수 밑을 입력 하시오 : ");
	up = inputUInt("* 양의 승을 입력 하시오 : ");
	res = ipow(down, up);
	printf("%d의 %d승은 %d입니다.\n\n", down, up, res);

	fdown = inputDouble("* 양의 실수 밑을 입력 하시오 : ");
	fup = inputUInt("* 양의 승을 입력 하시오 : ");
	fres = fpow(fdown, fup);
	printf("%.2lf의 %d승은 %.3lf입니다.\n", fdown, fup, fres);

	return 0;
}

void myflush(void) {
	while (getchar() != '\n');
	return;
}

int inputUInt(char *str) {
	int num;
	while (1) {
		printf("%s", str);
		scanf("%d", &num);
		if (num >= 0) {
			if (getchar() == '\n') { break; }
		}
		myflush();
	}
	return num;
}

double inputDouble(char *str) {
	double fnum;
	while (1) {
		printf("%s", str);
		scanf("%lf", &fnum);
		if (fnum >= 0.0) {
			if (getchar() == '\n') { break; }
		}
		myflush();
	}
	return fnum;
}
int ipow(int down, int up) {
	int res=1, i;
	if (down == 0) { res = 0; }
	else if (up == 0) { res = 1; }
	else {
		for (i = 0; i < up; i++) {
			res *= down;
		}
	}
	return res;
}
double fpow(double fdown, int fup) {
	double fres = 1;
	int i;
	if (fdown == 0) { fres = 0; }
	else if (fup == 0) { fres = 1; }
	else {
		for (i = 0; i < fup; i++) {
			fres *= fdown;
		}
	}
	return fres;
}