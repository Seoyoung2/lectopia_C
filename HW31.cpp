// 180110 이서영

#pragma warning(disable : 4996)
#include <stdio.h>

char menu(void);
int inputInt(char*);
void deposit(int, int*);
int withdraw(int, int*);
void myflush(void);

int main()
{
	int in, out,res=0, val = 0;
	char ch;

	printf("* 현재 잔액은 %d원 입니다.\n", val);
	while (1) {
		ch = menu();
		if (ch == 'q') { break; }
		switch (ch) {
		case 'i': 
			in = inputInt("# 입금액을 입력하세요 : ");
			deposit(in, &val);
			break;
		case 'o':
			out = inputInt("# 출금액을 입력하세요 : ");
			res = withdraw(out, &val);
			break;
		default:;
		}
		if (res == 1) { continue; }
	}
	return 0;
}

void myflush(void) {
	while (getchar() != '\n');
	return;
}

char menu(void) {
	char ch;
	while (1) {
		printf("\n# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
		scanf(" %c", &ch);
		if (ch == 'i' || ch == 'o' || ch == 'q') { break; }
		else {
			printf("* 잘못 입력하셨습니다.\n");
			myflush();
		}
	}
	return ch;
}
int inputInt(char *str) {
	int num, res;
	printf("%s", str);
	while (1) {
		res = scanf("%d", &num);
		if (res != 1) {
			printf("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
			myflush();
			continue;
		}
		else if (num < 0) {
			printf("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
			continue;
		}
		else if (getchar() == '\n') { break; }
	}
	return num;
}
void deposit(int in, int *pval) {
	*pval += in;
	printf("* 현재 잔액은 %d원 입니다.\n", *pval);
	return;
}
int withdraw(int out, int *pval) {
	int res=0;
	if (out > *pval) {
		printf("* 잔액이 부족합니다.\n");
		res = -1;
	}
	else {
		*pval -= out;
	}
	printf("* 현재 잔액은 %d원 입니다.\n", *pval);
	return res;
}