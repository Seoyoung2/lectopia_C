//180108 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

int main() {
	int ch;
	int eng=0, num=0, white=0, extra=0;
	printf("# ���� ������ �Է� �Ͻÿ� :\n");

	while ((ch = getchar()) != EOF) {
		if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))) {
			++eng;
		}
		else if ((ch >= '0') && (ch <= '9')) {
			++num;
		}
		else if ((ch == ' ') || (ch == '\t') || (ch == '\n')) {
			++white;
		}
		else {
			++extra;
		}
	}
	printf("* ������ ��ҹ��� ���� : %d��\n", eng);
	printf("* ���ڹ��� ���� : %d��\n", num);
	printf("* ���鹮��(space, tab, enter) ���� : %d��\n", white);
	printf("* �� �� ��Ÿ���� ���� : %d��\n", extra);

	return 0;
}