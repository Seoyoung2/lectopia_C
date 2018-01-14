// 180105 이서영

#pragma warning(disable : 4996)
#include <stdio.h>

int inputInt(const char*);
int cal(int, int);
void output(int, int, int);
void myflush(void);

int main() {
	int code, use, money;
	code = inputInt("* 사용자 코드를 입력하시오(1:가정용/2:상업용/3:공업용) : ");
	use = inputInt("* 사용량을 입력하시오(ton단위) : ");
	printf("\n");
	money = cal(code, use);
	output(code, use, money);
	return 0;
}

int inputInt(const char* str) {
	int n;
	while(1){
		printf("%s", str);
		scanf("%d", &n);
		if (getchar() == '\n') { break; }
		myflush();
	}
	return n;
}

void myflush(void) {
	while (getchar() != '\n');
	return;
}

int cal(int code, int use) {
	int money;
	switch (code) {
	case 1:
		money = (use * 50) * 105 / 100;
		break;
	case 2:
		money = (use * 45) * 105 / 100;
		break;
	case 3:
		money = (use * 30) * 105 / 100;
		break;
	default:;
	}
	return money;
}

void output(int code, int use, int money) {
	char *str=0;
	switch(code){
	case 1:
		str = "가정용";
		break;
	case 2:
		str = "상업용";
		break;
	case 3:
		str = "공업용";
		break;
	default:;
	}
	printf("# 사용자코드 : %d(%s)\n", code, str);
	printf("# 사용량 : %d ton\n", use);
	printf("# 총수도요금 : %d원\n", money);
	return;

}