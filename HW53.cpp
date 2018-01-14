// 180111 이서영

#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void inputStr(char *);
int checkStr(char *, int);
void output(char *, int);

int main() {
	char str[50];
	int check, len;

	inputStr(str);
	len = strlen(str);
	check = checkStr(str,len);
	output(str, check);

	return 0;
}

void inputStr(char*p) {
	printf("# 단어 입력 : ");
	scanf("%s", p);
	return;
}

int checkStr(char*p, int len) {
	int i,j, check=1;

	for (i = 0; i < len/2; i++) {
		if (tolower(p[i]) != tolower(p[len - i - 1])) {
			check = 0;
			break;
		}
	}
	return check;
}

void output(char *p, int check) {
	if (check == 0) {
		printf("\"%s\" : 회문이 아닙니다!\n", p);
	}
	else {
		printf("\"%s\" : 회문입니다!\n", p);
	}
	return;
}