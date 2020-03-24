#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int arg, int *argv[])
{
	char buf[2][2] = { {1,2}, {3, 4} };

	char *p_1 = buf;
	char *p_2 = &buf[0];
	char *p_3 = buf + 1;
	char *p_4 = &buf[0][0] + 1;

	getchar();
}