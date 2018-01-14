//180109 이서영

#pragma warning(disable : 4996)
#include<stdio.h>

int transNumber(int);
int inputUInt(char*);
void myflush(void);

int main() {
	int p1, p2, n, num, myn=0, count=0, i;

	p1 = inputUInt("시작 값(P1) : ");
	p2 = inputUInt("끝 값(P2) : ");
	n = inputUInt("고집수(N) : ");

	printf("고집수가 %d인 숫자 출력\n", n);
	for (i = p1; i <= p2; i++) {
		myn = 0;
		num = i;
		while (1) {
			if (num < 10) { break; }
			num = transNumber(num);
			myn++;
		}
		if (n == myn) {
			printf("%d\n", i);
			count++;
		}
	}
	printf("총 개수 : %d\n", count);
	return 0;
}

void myflush() {
	while (getchar() != '\n');
	return;
}

int inputUInt(char*str) {
	int num;
	while (1) {
		printf("%s", str);
		scanf("%d", &num);
		if (num > 0) {
			if (getchar() == '\n') { break; }
		}
		myflush();
	}
	return num;
}

int transNumber(int n) {
	int num;
	int one=1, ten=1, hun=1, tho=1;
	one = n % 10;
	ten = (n % 100 - one)/10;
	hun = (n % 1000 - ten * 10 - one)/100;
	tho = (n % 10000 - hun * 100 - ten * 10 - one)/1000;

	if (n > 99 && n < 1000) {
		tho = 1;
	}
	else if (n > 9 && n < 100) {
		tho = 1;
		hun = 1;
	}
	else if (n > 0 && n < 10) {
		tho = 1;
		hun = 1;
		ten = 1;
	}
	else { ; }

	num = one*ten*hun*tho;
	return num;
}