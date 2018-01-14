//180108 이서영

#pragma warning(disable : 4996)
#include <stdio.h>

int main() {
	int ch;
	int eng=0, num=0, white=0, extra=0;
	printf("# 영문 문장을 입력 하시오 :\n");

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
	printf("* 영문자 대소문자 개수 : %d개\n", eng);
	printf("* 숫자문자 개수 : %d개\n", num);
	printf("* 여백문자(space, tab, enter) 개수 : %d개\n", white);
	printf("* 그 외 기타문자 개수 : %d개\n", extra);

	return 0;
}