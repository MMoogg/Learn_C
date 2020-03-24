#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>

#pragma pack(8)
typedef struct abc
{
	unsigned char item1 : 2;
	unsigned char item2 : 1;
	unsigned char item3 : 7;
	unsigned char item4 : 6;
	unsigned char item5 : 4;
	unsigned char item6 : 4;

	unsigned char item7;
	unsigned long item8;
}ABC;

int main(int argc, char *argv[])
{
	ABC test, *p_test = NULL;

	unsigned char *p_char = NULL;
	unsigned long *p_long = NULL;
	unsigned int len_1, len_2, len_3;

	len_1 = sizeof(test);
	len_2 = sizeof(unsigned long);
	len_3 = sizeof(unsigned int);

	p_char = &test.item7;
	p_long = &test.item8;
	p_test = &test;

	getchar();
}