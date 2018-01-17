// 180117 이서영
// 주민등록번호 유효성 검사 프로그램

#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* 주민등록번호 길이*/
int availability_check(char *resident_number);
int length_character_check(char *resident_number);
int date_check(char *resident_number);
int identification_check(char *resident_number);
int gender_check(char *resident_number);
int year_check(int year);

int main()
{
	/* 테스트할 주민등록번호 저장 배열*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
		"8806311069417","8807311069418"
	};
	int i, count;
	/* 검사할 주민등록번호의 개수 계산*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i<count; i++) /* 주민등록번호 유효성 검사를 반복적으로 수행 함*/
	{
		if (availability_check(resident_number[i]) == TRUE)
		{
			printf("(+) 주민번호%s는(은) 유효한 번호입니다.\n", resident_number[i]);
		}
		else
		{
			printf("(-) 주민번호%s는(은) 유효하지 않은 번호입니다.\n", resident_number[i]);
		}
	}
	return 0;
}
/*----------------------------------------------------------------
availability_check()함수: 주민등록번호 유효성 검사 함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 유효하면TRUE, 유효하지 않으면FALSE 리턴
------------------------------------------------------------------*/
int availability_check(char *resident_number)
{
	if (length_character_check(resident_number)) { /* 길이 및 숫자문자 유효성검사*/
		if (gender_check(resident_number)) {  /* 성별식별번호 유효성 검사함수*/
			if (date_check(resident_number)) {  /* 날짜검사*/
				if (identification_check(resident_number)) {  /* 인식자 오류체크*/
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}
/*-------------------------------------------------------------------------
length_character_check()함수: 주민등록번호 길이 및 문자 유효성검사 함수
전달인자: 검사할 주민등록번호(문자열)
리턴값: 주민등록번호의 길이가 맞고 숫자문자로만 구성되어 있으면TRUE,
길이가 짧거나 길고, 숫자 문자가 아닌 문자가 섞여 있으면FALSE 리턴
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
date_check()함수: 첫6자리(연,월,일)의 유효성 검사 함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 유효한 날짜이면TRUE, 유효하지 않은 날짜이면FALSE 리턴
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
gender_check()함수: 7번째 자리의 성별식별번호 유효성 검사함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 성별식별번호가'1'~'4'이면TRUE, 그 외 숫자 문자이면FALSE 리턴
-----------------------------------------------------------------------*/
int gender_check(char *resident_number) {
	if (resident_number[6] == '1' || resident_number[6] == '2'||resident_number[6] == '3' || resident_number[6] == '4') {
		return TRUE;
	}
	else { return FALSE; }
}

/*------------------------------------------------------------------------
identification_check()함수: 주민등록번호 끝자리(인식자) 유효성 검사 함수
전달인자: 유효성 검사할 주민등록번호(문자열)
리턴값: 유효한 날짜이면TRUE, 유효하지 않은 날짜이면FALSE 리턴
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
year_check()함수: 년도의 윤,평년 여부 검사
전달인자: 윤,평년 검사할 년도
리턴값: 윤년이면1, 평년이면0 리턴
------------------------------------------------------------------*/
int year_check(int year) {	//1이면 윤년(29일-366일), 0이면 평년(28일-365일)
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

