// 180110 �̼���

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

	printf("* ���� �ܾ��� %d�� �Դϴ�.\n", val);
	while (1) {
		ch = menu();
		if (ch == 'q') { break; }
		switch (ch) {
		case 'i': 
			in = inputInt("# �Աݾ��� �Է��ϼ��� : ");
			deposit(in, &val);
			break;
		case 'o':
			out = inputInt("# ��ݾ��� �Է��ϼ��� : ");
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
		printf("\n# �޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");
		scanf(" %c", &ch);
		if (ch == 'i' || ch == 'o' || ch == 'q') { break; }
		else {
			printf("* �߸� �Է��ϼ̽��ϴ�.\n");
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
			printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
			myflush();
			continue;
		}
		else if (num < 0) {
			printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
			continue;
		}
		else if (getchar() == '\n') { break; }
	}
	return num;
}
void deposit(int in, int *pval) {
	*pval += in;
	printf("* ���� �ܾ��� %d�� �Դϴ�.\n", *pval);
	return;
}
int withdraw(int out, int *pval) {
	int res=0;
	if (out > *pval) {
		printf("* �ܾ��� �����մϴ�.\n");
		res = -1;
	}
	else {
		*pval -= out;
	}
	printf("* ���� �ܾ��� %d�� �Դϴ�.\n", *pval);
	return res;
}