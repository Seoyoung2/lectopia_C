// 180105 이서영

#pragma warning(disable : 4996)
#include <stdio.h>

int main() {
	int num, i=1, sum=0;

	for (i = 1; i <= 5; ) {
		printf("0보다 큰수를 입력하시오(%d 번째) : ", i);
		scanf("%d", &num);
		if (num > 0) {
			sum += num;
			i++;
		}
	}
	printf("입력된 값의 총 합 : %d\n", sum);
	return 0;
}