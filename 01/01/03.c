#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool my_str_cmp(char const *str1, char const *str2)
{
	bool res = false;

	if ((str1 != NULL) && (str2 != NULL))
	{
		if ( (*str1 == '\0') && (*str2 == '\0') )
		{
			return true;
		}

		do
		{
			if (*str1 != *str2)
			{
				res = false;
				break;
			}
			str1++;
			str2++;
		} while ((*str1 != '\0') && (*str2 != '\0'));

		if ((*str1 == '\0') && (*str2 == '\0'))
		{
			res = true;
		}
	}

	return res;
}

int main(int arg, int *argv[])
{
	printf("result %d\r\n", my_str_cmp("abcdefg", "fg"));
	printf("result %d\r\n", my_str_cmp("abcdefg", "a"));
	printf("result %d\r\n", my_str_cmp("abcdefg", "abc"));
	printf("result %d\r\n", my_str_cmp("abc", "abc"));
}