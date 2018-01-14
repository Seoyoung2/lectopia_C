// 180111 이서영

#pragma warning(disable : 4996)
#include <stdio.h>

char input(char*);
int strcheck(char*, char);

int main() {
	char str[100];
	char ch;
	int order;
	
	ch = input(str);
	order = strcheck(str, ch);
	if (order == -1) {
		printf("\"%s\"문자열 안에 '%c'문자는 존재하지 않습니다.\n", str, ch);
	}
	else {
		printf("\"%s\"문자열 안에 '%c'문자는 %d번 위치에 존재합니다.\n", str, ch, order);
	}
	return 0;
}

char input(char *str) {
	char ch;
	printf("# 문자열을 입력하시오 : ");
	scanf("%s", str);
	printf("# 문자를 입력하시오 : ");
	scanf(" %c", &ch);

	return ch;
}

int strcheck(char *str, char ch) {
	int i=0, index=-1;
	while (1) {
		if (str[i] == '\0') { break; }
		else if (ch == str[i]) {
			index = i;
			break;
		}
		i++;
	}
	return index;
}