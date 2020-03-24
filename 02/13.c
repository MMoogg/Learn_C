#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

bool binary_search_min_2_max(uint32_t const *array, uint32_t array_len, uint32_t item, uint32_t *result_index)
{
	bool ret = false;
	*result_index = 0;

	if (array != NULL)
	{
		int32_t search_begin = 0, search_end = array_len - 1, search_mid = 0;

		while ((search_begin <= search_end) && (search_begin >= 0) && (search_end >= 0) )
		{
			search_mid = (search_begin + search_end) / 2;

			if (array[search_mid] == item)
			{
				*result_index = search_mid;
				ret = true;
				break;
			}
			else if (array[search_mid] < item)
			{
				search_begin = search_mid + 1;
			}
			else
			{
				search_end = search_mid - 1;
			}
		}
	}

	return ret;
}


bool binary_search_max_2_min(uint32_t const *array, uint32_t array_len, uint32_t item, uint32_t *result_index)
{
	bool ret = false;
	*result_index = 0;

	if (array != NULL)
	{
		int32_t search_begin = 0, search_end = array_len - 1, search_mid = 0;

		while ( (search_begin <= search_end) && (search_begin < array_len) && ( search_end < array_len) )
		{
			search_mid = (search_begin + search_end) / 2;

			if (array[search_mid] == item)
			{
				*result_index = search_mid;
				ret = true;
				break;
			}
			else if (array[search_mid] < item)
			{
				search_end = search_mid - 1;
			}
			else
			{
				search_begin = search_mid + 1;
			}
		}
	}

	return ret;
}

uint32_t test_int_array_1[] = { 1, 2, 3, 4, 5, 6, 7 };
uint32_t test_int_array_2[] = { 7, 6, 5, 4, 3, 2, 1 };

int main(int argc, char *argv[])
{
	uint32_t result_index = 0;
	char res_buf[2][10] = { "false", "true" };
	bool ret;

	ret = binary_search_min_2_max(test_int_array_1, sizeof(test_int_array_1) / sizeof(uint32_t), 3, &result_index);
	printf("3 in array 1 is %s\r\n", res_buf[ret]);

	ret = binary_search_min_2_max(test_int_array_1, sizeof(test_int_array_1) / sizeof(uint32_t), 8, &result_index);
	printf("8 in array 1 is %s\r\n", res_buf[ret]);

	ret = binary_search_min_2_max(test_int_array_1, sizeof(test_int_array_1) / sizeof(uint32_t), 0, &result_index);
	printf("0 in array 1 is %s\r\n", res_buf[ret]);

	ret = binary_search_max_2_min(test_int_array_2, sizeof(test_int_array_2) / sizeof(uint32_t), 3, &result_index);
	printf("3 in array 2 is %s\r\n", res_buf[ret]);

	ret = binary_search_max_2_min(test_int_array_2, sizeof(test_int_array_2) / sizeof(uint32_t), 8, &result_index);
	printf("8 in array 2 is %s\r\n", res_buf[ret]);

	ret = binary_search_max_2_min(test_int_array_2, sizeof(test_int_array_2) / sizeof(uint32_t), 0, &result_index);
	printf("0 in array 2 is %s\r\n", res_buf[ret]);
}