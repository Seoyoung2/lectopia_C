// 180104 이서영

#pragma warning(disable : 4996)
#include <stdio.h>

int inputInt(void);
int cal(int);
void output(int, int);
void myflush(void);

int main() {
	int dep, day;

	dep = inputInt();
	day = cal(dep);
	output(dep, day);

	return 0;
}

int inputInt(void) {
	int dep;
	
	while (1) {
		printf("* 우물의 깊이를 입력하시오(cm단위) : ");
		if (scanf("%d", &dep) == 1) {
			break;
		}
		myflush();
	}
	return dep;
}

void myflush(void) {
	while (getchar() != '\n');
	return;
}

int cal(int dep) {
	int day=1, height = 0;
	
	if (dep == 0) {
		return 0;
	}
	while (1) {
		height += 50;
		if (height >= dep) {
			return day;
		}
		else {
			height -= 20;
			day++;
		}
	}
}

void output(int dep, int day) {
	printf("%.2lf 미터 깊이의 우물을 탈출하기 위해서는 %d일이 걸립니다.\n", dep*0.01, day);
	return;
}