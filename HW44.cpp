//180112 이서영

#pragma warning(disable : 4996)
#include <stdio.h>

int input(char *);
char evenodd(int, int);
void output(int, int, char);

int main() {
	int start, end;
	char ch;
	start = input("# 시작 값을 입력하시오 : ");
	while (1) {
		end = input("# 끝 값을 입력하시오 : ");
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
		printf("* %d~%d 까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요?(짝수:e/홀수:o) : ", start, end);
		scanf(" %c", &ch);
		if (ch == 'e' || ch == 'o') { break; }
	}
	return ch;
}
void output(int start, int end, char ch) {
	int i, sum=0;
	if (ch == 'e') {
		printf("%d~%d 까지의 짝수(", start, end);
		if (start % 2 == 1) {
			start++;
		}
	}
	else {
		printf("  %d~%d 까지의 홀수(", start, end);
		if (start % 2 == 0) {
			start++;
		}
	}
	for (i = start; i <= end; i+=2) {
		printf("%d ", i);
		sum += i;
	}
	printf("\b)의 합은 %d 입니다.\n", sum);
	return;

}