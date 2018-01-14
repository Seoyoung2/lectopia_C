// 180105 이서영

#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

int main() {
	char name[21];
	double height;
	char sex;
	int len;

	printf("# 성명 입력 : ");
	fgets(name, sizeof(name), stdin);
	len = strlen(name);
	name[len - 1] = '\0';
	
	printf("# 키 입력(cm단위) : ");
	scanf("%lf", &height);
	printf("# 성별입력(M/F) : ");
	scanf(" %c", &sex);

	if (sex == 'M'|| sex=='m') {
		printf("%s씨의 키는 %.2lfcm이고 남성입니다.\n", name, height);
	}
	else if(sex=='F' || sex=='f') {
		printf("%s씨의 키는 %.2lfcm이고 여성입니다.\n", name, height);
	}
	else {
		printf("오류\n");
	}
	return 0;
}