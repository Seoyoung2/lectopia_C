// 180105 �̼���

#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

int main() {
	char name[21];
	double height;
	char sex;
	int len;

	printf("# ���� �Է� : ");
	fgets(name, sizeof(name), stdin);
	len = strlen(name);
	name[len - 1] = '\0';
	
	printf("# Ű �Է�(cm����) : ");
	scanf("%lf", &height);
	printf("# �����Է�(M/F) : ");
	scanf(" %c", &sex);

	if (sex == 'M'|| sex=='m') {
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n", name, height);
	}
	else if(sex=='F' || sex=='f') {
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n", name, height);
	}
	else {
		printf("����\n");
	}
	return 0;
}