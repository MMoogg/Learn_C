#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>

bool zip_buffer(char const * input_str, char *result_str, uint32_t result_str_len)
{
	bool res = false;

	if ((input_str != NULL) && (result_str != NULL))
	{
		uint32_t input_buf_len = strlen(input_str);
		uint32_t save_index = 0, get_index = 0;
		uint32_t i = 0;
		char cmp_1 = '\0';
		char cmp_2 = '\0';
		uint32_t same_num_tmp = 0;
		char number_string[20];

		memset(result_str, 0, result_str_len);

		cmp_1 = input_str[get_index++];
		while (cmp_1 != '\0')
		{
			same_num_tmp = 1;
			cmp_2 = input_str[get_index++];

			while (cmp_1 == cmp_2)
			{
				same_num_tmp++;
				cmp_2 = input_str[get_index++];
			}

			if (same_num_tmp == 1)
			{
				result_str[save_index++] = cmp_1;
			}
			else
			{
				sprintf_s(number_string, 10, "%d", same_num_tmp);
				strcpy_s(result_str + save_index, 10, number_string);
				save_index += strlen(number_string);
				result_str[save_index++] = cmp_1;
			}
			cmp_1 = cmp_2;
		}
		res = true;
	}

	return res;
}

int main(int argc, char *argv[])
{
	char input_buf[100];
	char ressult_buf[100];
	printf("Input the original string: \r\n");

	scanf_s("%s", input_buf, 99);
	if (zip_buffer(input_buf, ressult_buf, 100))
	{
		printf("%s", ressult_buf);
	}
}