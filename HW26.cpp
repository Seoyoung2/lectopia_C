//180108 �̼���

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
	printf("���Ӱ�� : %d �� %d ��\n", victory, same);
	return 0;
}

int inputInt(void) {
	int num;
	while (1) {
		printf("# ������ 1, ������ 2, ���� 3 �߿��� �����ϼ��� : ");
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
	case 1: mystr = "����"; break;
	case 2: mystr = "����"; break;
	case 3: mystr = "��"; break;
	default:;
	}
	switch (com) {
	case 1: comstr = "����"; break;
	case 2: comstr = "����"; break;
	case 3: comstr = "��"; break;
	default:;
	}

	if (my == com) {
		printf("  ����� %s ����, ��ǻ�ʹ� %s ���� : �����ϴ�.\n", mystr, comstr);
		res = 0;
	}
	else if ((my == 3 && com == 1) || (my == 1 && com == 2) || (my == 2 || com == 3)) {
		printf("  ����� %s ����, ��ǻ�ʹ� %s ���� : �̰���ϴ�.\n", mystr, comstr);
		res = 1;
	}
	else {
		printf("  ����� %s ����, ��ǻ�ʹ� %s ���� : ����� �����ϴ�.\n", mystr, comstr);
		res = -1;
	}
	return res;
}