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
	printf("몸무게를 입력하세요(kg) : ");
	scanf("%d", &wei);
	return wei;
}

double in_height() {
	double hei;
	printf("키를 입렵하세요(m) : ");
	scanf("%lf", &hei);
	return hei;
}

double cal(int wei, double hei) {
	double bmi = wei / (hei*hei);
	return bmi;
}

void printresult(double bmi) {

	if (bmi >= 40.0) {
		printf("당신의 BMI는 %.1lf으로 고도비만입니다\n", bmi);
	}
	else if (bmi >= 30.0) {
		printf("당신의 BMI는 %.1lf으로 비만입니다\n", bmi);
	}
	else if (bmi >= 25.0) {
		printf("당신의 BMI는 %.1lf으로 과체중입니다\n", bmi);
	}
	else if (bmi >= 18.5) {
		printf("당신의 BMI는 %.1lf으로 정상체중입니다\n", bmi);
	}
	else{
		printf("당신의 BMI는 %.1lf으로 저체중입니다\n", bmi);
	}
	return;
}