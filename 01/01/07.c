#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>


bool file_same_char_in_string(char const * input_str, char *result_str, uint32_t result_str_len)
{
	bool res = false;

	if ((input_str != NULL) && (result_str != NULL))
	{
		uint32_t input_buf_len = strlen(input_str);
		uint32_t save_index = 0;
		uint32_t i = 0;
		char tmp_buf[2] = { 0, 0 };

		memset(result_str, 0, result_str_len);

		for (i = 0; ( ( i < input_buf_len ) && (save_index <= (result_str_len - 1) ) ); i++)
		{
			tmp_buf[0] = input_str[i];
			if ( strstr(result_str, tmp_buf) == 0)
			{
				result_str[save_index++] = input_str[i];
			}
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
	if (file_same_char_in_string(input_buf, ressult_buf, 100))
	{
		printf("%s", ressult_buf);
	}
	
}