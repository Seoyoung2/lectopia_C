// 180117 �̼���
// �ֹε�Ϲ�ȣ ��ȿ�� �˻� ���α׷�

#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* �ֹε�Ϲ�ȣ ����*/
int availability_check(char *resident_number);
int length_character_check(char *resident_number);
int date_check(char *resident_number);
int identification_check(char *resident_number);
int gender_check(char *resident_number);
int year_check(int year);

int main()
{
	/* �׽�Ʈ�� �ֹε�Ϲ�ȣ ���� �迭*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
		"8806311069417","8807311069418"
	};
	int i, count;
	/* �˻��� �ֹε�Ϲ�ȣ�� ���� ���*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i<count; i++) /* �ֹε�Ϲ�ȣ ��ȿ�� �˻縦 �ݺ������� ���� ��*/
	{
		if (availability_check(resident_number[i]) == TRUE)
		{
			printf("(+) �ֹι�ȣ%s��(��) ��ȿ�� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
		else
		{
			printf("(-) �ֹι�ȣ%s��(��) ��ȿ���� ���� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
	}
	return 0;
}
/*----------------------------------------------------------------
availability_check()�Լ�: �ֹε�Ϲ�ȣ ��ȿ�� �˻� �Լ�
��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
���ϰ�: ��ȿ�ϸ�TRUE, ��ȿ���� ������FALSE ����
------------------------------------------------------------------*/
int availability_check(char *resident_number)
{
	if (length_character_check(resident_number)) { /* ���� �� ���ڹ��� ��ȿ���˻�*/
		if (gender_check(resident_number)) {  /* �����ĺ���ȣ ��ȿ�� �˻��Լ�*/
			if (date_check(resident_number)) {  /* ��¥�˻�*/
				if (identification_check(resident_number)) {  /* �ν��� ����üũ*/
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}
/*-------------------------------------------------------------------------
length_character_check()�Լ�: �ֹε�Ϲ�ȣ ���� �� ���� ��ȿ���˻� �Լ�
��������: �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
���ϰ�: �ֹε�Ϲ�ȣ�� ���̰� �°� ���ڹ��ڷθ� �����Ǿ� ������TRUE,
���̰� ª�ų� ���, ���� ���ڰ� �ƴ� ���ڰ� ���� ������FALSE ����
--------------------------------------------------------------------------*/
int length_character_check(char *resident_number) {
	int i;
	if (resident_number[RESIDENT_NUMBER_LENGTH] != '\0') {
		return FALSE;
	}
	for (i = 0; i < RESIDENT_NUMBER_LENGTH; i++) {
		if (resident_number[i] < '0'&&resident_number[i] > '9') {
			return FALSE;
		}
	}
	return TRUE;
}

/*----------------------------------------------------------------
date_check()�Լ�: ù6�ڸ�(��,��,��)�� ��ȿ�� �˻� �Լ�
��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
���ϰ�: ��ȿ�� ��¥�̸�TRUE, ��ȿ���� ���� ��¥�̸�FALSE ����
------------------------------------------------------------------*/
int date_check(char *resident_number) {
	int year, month, day;
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	year = 1900 + (resident_number[0]-'0') * 10 + (resident_number[1]-'0');
	if (resident_number[6] == '3' || resident_number[6] == '4') {
		year += 100;
	}
	month = (resident_number[2]-'0') * 10 + (resident_number[3]-'0');
	day = (resident_number[4]-'0') * 10 + (resident_number[5]-'0');
	
	if (year >= 1900) {
		if (month >= 1 && month <= 12) {
			if (month == 2) {
				if (year_check(year) == 0) {
					if (day >= 1 && day <= 28) { return TRUE; }
				}
				else {
					if (day >= 1 && day <= 29) { return TRUE; }
				}
			}
			else if (day >= 1 && day <= mon[month - 1]) { return TRUE; }
		}
	}
	return FALSE;
}

/*----------------------------------------------------------------------
gender_check()�Լ�: 7��° �ڸ��� �����ĺ���ȣ ��ȿ�� �˻��Լ�
��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
���ϰ�: �����ĺ���ȣ��'1'~'4'�̸�TRUE, �� �� ���� �����̸�FALSE ����
-----------------------------------------------------------------------*/
int gender_check(char *resident_number) {
	if (resident_number[6] == '1' || resident_number[6] == '2'||resident_number[6] == '3' || resident_number[6] == '4') {
		return TRUE;
	}
	else { return FALSE; }
}

/*------------------------------------------------------------------------
identification_check()�Լ�: �ֹε�Ϲ�ȣ ���ڸ�(�ν���) ��ȿ�� �˻� �Լ�
��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
���ϰ�: ��ȿ�� ��¥�̸�TRUE, ��ȿ���� ���� ��¥�̸�FALSE ����
-------------------------------------------------------------------------*/
int identification_check(char *resident_number) {
	int i, sum = 0, check;
	for (i = 0; i < RESIDENT_NUMBER_LENGTH-1; i++) {
		sum += (resident_number[i]-'0');
	}
	check = sum % 10;
	if (check == (resident_number[RESIDENT_NUMBER_LENGTH - 1]-'0')) {
		return TRUE;
	}
	else { return FALSE; }
}

/*----------------------------------------------------------------
year_check()�Լ�: �⵵�� ��,��� ���� �˻�
��������: ��,��� �˻��� �⵵
���ϰ�: �����̸�1, ����̸�0 ����
------------------------------------------------------------------*/
int year_check(int year) {	//1�̸� ����(29��-366��), 0�̸� ���(28��-365��)
	if (year % 4 != 0) {
		return 0;
	}
	else {
		if (year % 100 != 0) {
			return 1;
		}
		else {
			if (year % 400 == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
}

