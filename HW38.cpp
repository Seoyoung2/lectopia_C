// 180105 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>


int main() {
	int i;
	int money, bread, snack, drink;

	while (1) {
		printf("���� ����� ���� �ݾ� �Է� : ");
		scanf("%d", &money);
		if (getchar() != '\n') { break; }

		for (bread = 1; bread * 500 <= money; bread++) {
			for (snack = 1; snack * 700 <= (money-bread*500); snack++) {
				for (drink = 1; drink * 400 <= (money-bread*500-snack*700); drink++) {
					if (money == bread * 500 + snack * 700 + drink * 400) {
						printf("ũ����(%d ��), �����(%d ����), �ݶ�(%d ��)\n", bread, snack, drink);
					}
				}
			}
		}
		printf("��� �����Ͻðڽ��ϱ�?\n");
		printf("\n");
	}
	return 0;
}