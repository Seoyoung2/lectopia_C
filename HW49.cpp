// 180111 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>

void swap(int *,int);

int main() {
	int i;
	int arr[8] = { 1,2,3,4,5,6,7,8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("ó�� �迭�� ����� �� : ");
	for (i = 0; i < size; i++) {
		printf("  %d", arr[i]);
	}
	swap(arr,size);
	printf("\n�ٲ� �迭�� ����� �� : ");
	for (i = 0; i < size; i++) {
		printf("  %d", arr[i]);
	}
	printf("\n");

	return 0;
}

void swap(int *p, int size) {
	int i, temp;
	for (i = 0; i < size / 2; i++) {
		temp = p[i];
		p[i] = p[size - i-1];
		p[size - i - 1] = temp;
	}
	return;
}