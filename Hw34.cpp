// 180105 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

int inputInt(const char*);
int cal(int, int);
void output(int, int, int);
void myflush(void);

int main() {
	int code, use, money;
	code = inputInt("* ����� �ڵ带 �Է��Ͻÿ�(1:������/2:�����/3:������) : ");
	use = inputInt("* ��뷮�� �Է��Ͻÿ�(ton����) : ");
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
		str = "������";
		break;
	case 2:
		str = "�����";
		break;
	case 3:
		str = "������";
		break;
	default:;
	}
	printf("# ������ڵ� : %d(%s)\n", code, str);
	printf("# ��뷮 : %d ton\n", use);
	printf("# �Ѽ������ : %d��\n", money);
	return;

}