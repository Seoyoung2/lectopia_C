/*#include<stdio.h>

int main() {
	int money = 278970;
	int five_m, m, five_c, c, five_b, b, five_s, s;

	five_m = money / 50000;
	printf("50000���� => %d��\n", five_m);
	m = (money-five_m*50000) / 10000;
	printf("10000���� => %d��\n", m);
	five_c = (money-five_m*50000-m*10000) / 5000;
	printf("5000���� => %d��\n", five_c);
	c = (money-five_m*50000-m*10000-five_c*5000) / 1000;
	printf("1000���� => %d��\n", c);
	five_b = (money-five_m*50000-m*10000-five_c*5000-c*1000) / 500;
	printf("500���� => %d��\n", five_b);
	b = (money - five_m * 50000 - m * 10000 - five_c * 5000 - c*1000 - five_b*500 ) / 100;
	printf("100���� => %d��\n", b);
	five_s = (money - five_m * 50000 - m * 10000 - five_c * 5000 - c * 1000 - five_b*500 - b*100 ) / 50;
	printf("50���� => %d��\n", five_s);
	s = (money - five_m * 50000 - m * 10000 - five_c * 5000 - c * 1000 - five_b * 500 - b * 100 - five_c * 50) / 10;
	printf("10���� => %d��\n", s);

	return 0;
}
*/