//180112 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

int input(char *);
char evenodd(int, int);
void output(int, int, char);

int main() {
	int start, end;
	char ch;
	start = input("# ���� ���� �Է��Ͻÿ� : ");
	while (1) {
		end = input("# �� ���� �Է��Ͻÿ� : ");
		if (end > start) { break; }
		else { ; }
	}
	ch = evenodd(start, end);
	output(start, end, ch);
	return 0;
}

int input(char *str) {
	int res, num;
	while (1) {
		printf("%s", str);
		res = scanf("%d", &num);
		if (res == 1) {
			if (num >= 0) { break; }
		}
		else { ; }
	}
	return num;
}
char evenodd(int start, int end) {
	char ch;
	while (1) {
		printf("* %d~%d ������ ¦���� ���� ���ұ��? Ȧ���� ���� ���ұ��?(¦��:e/Ȧ��:o) : ", start, end);
		scanf(" %c", &ch);
		if (ch == 'e' || ch == 'o') { break; }
	}
	return ch;
}
void output(int start, int end, char ch) {
	int i, sum=0;
	if (ch == 'e') {
		printf("%d~%d ������ ¦��(", start, end);
		if (start % 2 == 1) {
			start++;
		}
	}
	else {
		printf("  %d~%d ������ Ȧ��(", start, end);
		if (start % 2 == 0) {
			start++;
		}
	}
	for (i = start; i <= end; i+=2) {
		printf("%d ", i);
		sum += i;
	}
	printf("\b)�� ���� %d �Դϴ�.\n", sum);
	return;

}