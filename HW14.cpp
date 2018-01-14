// 180103 이서영

#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

int main()
{
	int len;
	char str[31];

	printf("* 문자열 입력 : ");
	scanf("%s", str);

	len = strlen(str);

	printf("[%*.*s...]\n", len,len/2, str);
	return 0;
}