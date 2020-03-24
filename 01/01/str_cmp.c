#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MY_MAX(a, b) ((a) > (b) ? (a) : (b))

bool str_in_judge(char *source, char *cmp)
{
	bool ret = false;

	if ( (source != NULL) && (cmp != NULL) )
	{
		while (*source != '\0')
		{
			if (*source == *cmp)
			{
				do
				{
					if (*++cmp != *++source)
					{
						break;
					}
				} while ((*cmp != '\0') && (*source != '\0'));

				if (*cmp == '\0')
				{
					ret = true;
					break;
				}
			}
			else
			{
				source++;
			}

		}
	}

	return ret;
}

int main(int arg, int *argv[])
{
	printf("result %d\r\n", str_in_judge("abcdefg", "fg"));
	printf("result %d\r\n", str_in_judge("a", "fg"));
	printf("result %d\r\n", str_in_judge("abcdefg", "h"));
	printf("result %d\r\n", str_in_judge("abcdefg", "e"));
	printf("result %d\r\n", str_in_judge("abcdefg", "dh"));

	printf("result %d\r\n", MY_MAX(10, 8));

	getchar();
}
