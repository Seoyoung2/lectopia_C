//180112 이서영

#pragma warning(disable : 4996)
#include <stdio.h>

void inputStr(char*);
int calNumber(char*);
void output(char*, int);

int main() {
	char str[100];
	int sum;
	inputStr(str);
	sum = calNumber(str);
	output(str, sum);

	return 0;
}

void inputStr(char *str) {
	printf("# 문장을 입력하시오 : ");
	scanf("%s", str);
	return;
}

int calNumber(char* str) {
	int i=0, sum=0, num, tmp=0;
	while (str[i] != '\0') {
		if (str[i] >= '0'&&str[i] <= '9') {
			num = str[i] - '0';
			tmp += num;
			if (str[i + 1] >= '0'&&str[i + 1] <= '9') {
				tmp *= 10;
			}
		}
		else {
			sum += tmp;
			tmp = 0;
		}
		i++;
	}
	sum += tmp;
	return sum;
}

void output(char* str, int sum) {
	printf("\"%s\" 내의 총 숫자는 [%d]입니다.\n", str, sum);
	return;
}
