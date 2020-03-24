#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool two_side_equal(char *str)
{
	bool ret = false;

	if (str != NULL)
	{
		int str_len = 0;
		int cmp_len = 0;
		int index;

		str_len = strlen(str);
		cmp_len = str_len / 2;

		for (index = 0; index < cmp_len; index++)
		{
			if (str[index] != str[str_len - index - 1])
			{
				break;
			}
		}
		if (index == cmp_len)
		{
			ret = true;
		}
	}

	return ret;
}

int main(int arg, int *argv[])
{
	printf("result %d\r\n", two_side_equal("abcdefg"));
	printf("result %d\r\n", two_side_equal("abcdef"));
	printf("result %d\r\n", two_side_equal("aabaa"));
	printf("result %d\r\n", two_side_equal("aba"));
	printf("result %d\r\n", two_side_equal("aaaa"));
	printf("result %d\r\n", two_side_equal("aa"));
}