#include<stdio.h>
#pragma warning(disable:4996)

int in_weight();
double in_height();
double cal(int wei, double hei);
void printresult(double bmi);

int main() {
	int wei;
	double hei, bmi;
	wei = in_weight();
	hei = in_height();
	bmi = cal(wei, hei);
	printresult(bmi);

	return 0;
}

int in_weight() {
	int wei;
	printf("�����Ը� �Է��ϼ���(kg) : ");
	scanf("%d", &wei);
	return wei;
}

double in_height() {
	double hei;
	printf("Ű�� �Է��ϼ���(m) : ");
	scanf("%lf", &hei);
	return hei;
}

double cal(int wei, double hei) {
	double bmi = wei / (hei*hei);
	return bmi;
}

void printresult(double bmi) {

	if (bmi >= 40.0) {
		printf("����� BMI�� %.1lf���� �����Դϴ�\n", bmi);
	}
	else if (bmi >= 30.0) {
		printf("����� BMI�� %.1lf���� ���Դϴ�\n", bmi);
	}
	else if (bmi >= 25.0) {
		printf("����� BMI�� %.1lf���� ��ü���Դϴ�\n", bmi);
	}
	else if (bmi >= 18.5) {
		printf("����� BMI�� %.1lf���� ����ü���Դϴ�\n", bmi);
	}
	else{
		printf("����� BMI�� %.1lf���� ��ü���Դϴ�\n", bmi);
	}
	return;
}