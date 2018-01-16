//180116 이서영
// 문자열 첫 문자와 마지막 문자 출력하기

#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

void inputArr(char (*)[20]);
void sortStr(char (*)[20]);
void outputStr(char (*)[20]);

int main(void) {
	char str[5][20];

	inputArr(str);
	sortStr(str);
	printf("\n");
	outputStr(str);

	return 0;
}

void inputArr(char(*str)[20]) {
	int i;
	for (i = 0; i < 5; i++) {
		printf("# %d번 문자열을 입력하시오 : ", i + 1);
		scanf("%s", str[i]);
	}
	return;
}

void sortStr(char(*str)[20]) {
	int i, j;
	char temp[20];
	for (i = 0; i < 4; i++) {
		for (j = i + 1; j < 5; j++) {
			if (strcmp(str[i], str[j])>0) {
				strcpy(temp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], temp);
			}
			else { ; }
		}
	}
	return;
}

void outputStr(char(*str)[20]) {
	int i, len;
	for (i = 0; i < 5; i++) {
		len = strlen(str[i]);
		printf("str[%d] = %s  %c  %c\n", i, str[i], str[i][0], str[i][len-1]);
	}
	return;
}