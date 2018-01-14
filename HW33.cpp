//180112 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

int menu(void);
unsigned char openFan(unsigned char);
unsigned char offFan(unsigned char);
unsigned char reverseFan(unsigned char);
void displayFan(unsigned char);

int main() {
	unsigned char status = 0;
	int num;

	while (1) {
		num = menu();
		if (num == 1) {
			status = openFan(status);
		}
		else if (num == 2) {
			status = offFan(status);
		}
		else if (num == 3) {
			status = reverseFan(status);
		}
		else {
			break;
		}
		displayFan(status);
	}
	return 0;
}

int menu(void) {
	int num;
	while (1) {
		printf("1. ȯǳ�� ���� / 2. ȯǳ�� �ݱ� / 3. ȯǳ�� ��ü ��ȯ / 4. ���� : ");
		scanf("%d", &num);
		if (num == 1 || num == 2 || num == 3 || num == 4) { break; }
		else{ while (getchar() != '\n'); }
	}
	return num;
}

unsigned char openFan(unsigned char status) {
	int n;
	unsigned char temp=1;
	printf("-----------------------------------------------------------\n");
	printf("\t\tFan ���� �۾� ���� ȭ��\n");
	printf("-----------------------------------------------------------\n");
	while (1) {
		printf("* OPEN�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
		scanf("%d", &n);
		if (n >= 1 && n <= 8) { break; }
		else { while (getchar() != '\n'); }
	}
	temp <<= (n - 1);
	status |= temp;
	return status;
}
unsigned char offFan(unsigned char status) {
	int n;
	unsigned char temp = 1;
	printf("-----------------------------------------------------------\n");
	printf("\t\tFan �ݱ� �۾� ���� ȭ��\n");
	printf("-----------------------------------------------------------\n");
	while (1) {
		printf("* CLOSE�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
		scanf("%d", &n);
		if (n >= 1 && n <= 8) { break; }
		else { while (getchar() != '\n'); }
	}
	temp = 0xff ^ (temp << (n - 1));
	status &= temp;
	return status;
}
unsigned char reverseFan(unsigned char status) {
	unsigned char temp = 1;
	printf("-----------------------------------------------------------\n");
	printf("\t\tFan ��ü ��ȯ �۾� ���� ȭ��\n");
	printf("-----------------------------------------------------------\n");
	printf("��ü FAN�� ���°� ��ȯ�Ǿ����ϴ�. (ON, OFF ���� �ڹٲ�)\n");

	status = ~status;
	return status;
}
void displayFan(unsigned char status) {
	unsigned char temp = 0x80;
	int i;
	printf("-----------------------------------------------------------\n");
	printf("8��FAN  7��FAN  6��FAN  5��FAN  4��FAN  3��FAN  2��FAN  1��FAN  \n");
	for (i = 0; i < 8; i++) {
		if ((status&temp) == 0) {
			printf(" OFF    ");
		}
		else {
			printf("  ON    ");
		}
		temp >>= 1;
	}
	printf("\n-----------------------------------------------------------\n");
}