//180112 이서영

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
		printf("1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
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
	printf("\t\tFan 열기 작업 실행 화면\n");
	printf("-----------------------------------------------------------\n");
	while (1) {
		printf("* OPEN할 FAN 번호를 입력하시오(1-8) : ");
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
	printf("\t\tFan 닫기 작업 실행 화면\n");
	printf("-----------------------------------------------------------\n");
	while (1) {
		printf("* CLOSE할 FAN 번호를 입력하시오(1-8) : ");
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
	printf("\t\tFan 전체 전환 작업 실행 화면\n");
	printf("-----------------------------------------------------------\n");
	printf("전체 FAN의 상태가 전환되었습니다. (ON, OFF 상태 뒤바뀜)\n");

	status = ~status;
	return status;
}
void displayFan(unsigned char status) {
	unsigned char temp = 0x80;
	int i;
	printf("-----------------------------------------------------------\n");
	printf("8번FAN  7번FAN  6번FAN  5번FAN  4번FAN  3번FAN  2번FAN  1번FAN  \n");
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