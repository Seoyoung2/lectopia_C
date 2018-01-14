// 180105 이서영

#pragma warning(disable : 4996)
#include <stdio.h>


int main() {
	int i;
	int money, bread, snack, drink;

	while (1) {
		printf("현재 당신의 소유 금액 입력 : ");
		scanf("%d", &money);
		if (getchar() != '\n') { break; }

		for (bread = 1; bread * 500 <= money; bread++) {
			for (snack = 1; snack * 700 <= (money-bread*500); snack++) {
				for (drink = 1; drink * 400 <= (money-bread*500-snack*700); drink++) {
					if (money == bread * 500 + snack * 700 + drink * 400) {
						printf("크림빵(%d 개), 새우깡(%d 봉지), 콜라(%d 병)\n", bread, snack, drink);
					}
				}
			}
		}
		printf("어떻게 구입하시겠습니까?\n");
		printf("\n");
	}
	return 0;
}