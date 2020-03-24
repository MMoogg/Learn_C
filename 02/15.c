/*
Advance topics in c, chapter one
*/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>


void merge_two_min_t_max_array(uint32_t *res, uint32_t const *array_1, uint32_t const *array_2, uint32_t array_1_len, uint32_t array_2_len)
{
	if ( (res != NULL) && (array_1 != NULL) && (array_2 != NULL) && (array_1_len > 0) && (array_2_len > 0) )
	{
		uint32_t array_1_cmp_index = 0, array_2_cmp_index = 0, res_index = 0;
		uint32_t compare_base = array_1[0];

		while ( (array_1_cmp_index < array_1_len) && (array_2_cmp_index < array_2_len) )
		{
			compare_base = array_1[array_1_cmp_index++];
			while (compare_base > array_2[array_2_cmp_index])
			{
				res[res_index++] = array_2[array_2_cmp_index++];
			}
			if (compare_base != array_2[array_2_cmp_index])
			{
				res[res_index++] = compare_base;
			}		
		}

		if (array_1_cmp_index < array_1_len)
		{
			memcpy( res + res_index, array_1 + array_1_cmp_index, (array_1_len - array_1_cmp_index) * sizeof(uint32_t) );
		}
		else if (array_2_cmp_index < array_2_len)
		{
			memcpy(res + res_index, array_2 + array_2_cmp_index, (array_2_len - array_2_cmp_index) * sizeof(uint32_t));
		}
		else
		{
			;
		}
	}
}

uint32_t test_buf_1[] = { 1, 2, 5, 7, 8, 10 };
uint32_t test_buf_2[] = { 3, 4, 9, 12, 14, 15 };
uint32_t test_buf_3[] = { 11, 12, 15, 17, 18, 40 };
uint32_t test_buf_4[] = { 0, 1, 7, 8, 11, 12, 15, 10, 100 };
uint32_t meg_res_buf[50];

int main(int argc, char *argv[])
{
	memset(meg_res_buf, 0, 100 * sizeof(uint32_t));
	merge_two_min_t_max_array(meg_res_buf, test_buf_1, test_buf_2, sizeof(test_buf_1) / sizeof(uint32_t), sizeof(test_buf_2) / sizeof(uint32_t) );
	
	memset(meg_res_buf, 0, 100 * sizeof(uint32_t));
	merge_two_min_t_max_array(meg_res_buf, test_buf_2, test_buf_3, sizeof(test_buf_2) / sizeof(uint32_t), sizeof(test_buf_3) / sizeof(uint32_t) );
	
	memset(meg_res_buf, 0, 100 * sizeof(uint32_t));
	merge_two_min_t_max_array(meg_res_buf, test_buf_3, test_buf_4, sizeof(test_buf_3) / sizeof(uint32_t), sizeof(test_buf_4) / sizeof(uint32_t) );
	
	memset(meg_res_buf, 0, 100 * sizeof(uint32_t));
	merge_two_min_t_max_array(meg_res_buf, test_buf_1, test_buf_4, sizeof(test_buf_1) / sizeof(uint32_t), sizeof(test_buf_4) / sizeof(uint32_t) );

	getchar();
}
