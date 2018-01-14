// 180103 이서영

#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

int main()
{
	unsigned int f_len, len;
	char f_name[15];
	char name[15];

	printf("#성을 입력하시오 : ");
	scanf("%s", f_name);
	printf("#이름을 입력하시오 : ");
	scanf("%s", name);

	f_len = strlen(f_name);
	len = strlen(name);
	printf("%s %s\n", f_name, name);
	printf("%*d %*d\n", f_len, f_len, len, len);
	return 0;
}
