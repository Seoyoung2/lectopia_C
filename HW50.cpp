// 180111 �̼���

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
		printf("\"%s\"���ڿ� �ȿ� '%c'���ڴ� �������� �ʽ��ϴ�.\n", str, ch);
	}
	else {
		printf("\"%s\"���ڿ� �ȿ� '%c'���ڴ� %d�� ��ġ�� �����մϴ�.\n", str, ch, order);
	}
	return 0;
}

char input(char *str) {
	char ch;
	printf("# ���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", str);
	printf("# ���ڸ� �Է��Ͻÿ� : ");
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