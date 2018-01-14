//180108 이서영

#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputInt(void);
int output(int, int);
void myflush(void);

int main() {
	int my, com, randnum, victory=0, same=0, res;
	srand((unsigned int)time(NULL));

	while (1) {
		my = inputInt();
		randnum = rand() % 3;
		com = randnum + 1;
		res = output(my, com);
		if (res == -1) { break; }
		else if (res == 0) { ++same; }
		else { ++victory; }
	}
	printf("게임결과 : %d 승 %d 무\n", victory, same);
	return 0;
}

int inputInt(void) {
	int num;
	while (1) {
		printf("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
		scanf("%d", &num);
		if (getchar() != '\n') {
			myflush();
			continue;
		}
		if (num == 1 || num == 2 || num == 3) {break;}
	}
	return num;
}

void myflush(void) {
	while (getchar() != '\n');
	return;
}

int output(int my, int com) {
	char *mystr=0;
	char *comstr=0;
	int res;

	switch (my) {
	case 1: mystr = "바위"; break;
	case 2: mystr = "가위"; break;
	case 3: mystr = "보"; break;
	default:;
	}
	switch (com) {
	case 1: comstr = "바위"; break;
	case 2: comstr = "가위"; break;
	case 3: comstr = "보"; break;
	default:;
	}

	if (my == com) {
		printf("  당신은 %s 선택, 컴퓨터는 %s 선택 : 비겼습니다.\n", mystr, comstr);
		res = 0;
	}
	else if ((my == 3 && com == 1) || (my == 1 && com == 2) || (my == 2 || com == 3)) {
		printf("  당신은 %s 선택, 컴퓨터는 %s 선택 : 이겼습니다.\n", mystr, comstr);
		res = 1;
	}
	else {
		printf("  당신은 %s 선택, 컴퓨터는 %s 선택 : 당신이 졌습니다.\n", mystr, comstr);
		res = -1;
	}
	return res;
}