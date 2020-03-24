#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>


bool find_max_int_array(uint32_t const *array, uint32_t *index, uint32_t len)
{
	bool ret = false;

	if ((array != NULL) && (index != NULL))
	{
		uint32_t i, max_value = array[0];
		*index = 0;

		for (i = 1; i < len; i++)
		{
			if (array[i] > max_value)
			{
				max_value = array[i];
				*index = i;
			}
		}

		ret = true;
	}

	return ret;
}


bool find_min_int_array(uint32_t const *array, uint32_t *index, uint32_t len)
{
	bool ret = false;

	if ((array != NULL) && (index != NULL))
	{
		uint32_t i, min_value = array[0];
		*index = 0;

		for (i = 1; i < len; i++)
		{
			if (array[i] < min_value)
			{
				min_value = array[i];
				*index = i;
			}
		}

		ret = true;
	}

	return ret;
}


bool select_sort_int_max_2_min(uint32_t *array, uint32_t len)
{
	bool ret = false;

	if ((array != NULL) && (len > 0))
	{
		uint32_t *comp_p = array;
		uint32_t i, tmp_max_index, tmp;

		for (i = 0; i <= (len - 2); i++)
		{
			comp_p = array + i;
			find_max_int_array(comp_p, &tmp_max_index, len - i);
			tmp = comp_p[0];
			comp_p[0] = comp_p[tmp_max_index];
			comp_p[tmp_max_index] = tmp;
		}

		ret = true;
	}
	return ret;
}

bool select_sort_int_min_2_max(uint32_t *array, uint32_t len)
{
	bool ret = false;

	if ((array != NULL) && (len > 0))
	{
		uint32_t *comp_p = array;
		uint32_t i, tmp_min_index, tmp;

		for (i = 0; i <= (len - 2); i++)
		{
			comp_p = array + i;
			find_min_int_array(comp_p, &tmp_min_index, len - i);
			tmp = comp_p[0];
			comp_p[0] = comp_p[tmp_min_index];
			comp_p[tmp_min_index] = tmp;
		}

		ret = true;
	}
	return ret;
}

static uint32_t test_array_1[] = { 172, 234, 8909, 239982, 1, 8989 };
static uint32_t test_array_2[] = { 1, 323, 234, 5332, 28109 };

int main(int argc, char *argv[])
{

	select_sort_int_max_2_min(test_array_1, sizeof(test_array_1) / sizeof(uint32_t));
	select_sort_int_max_2_min(test_array_2, sizeof(test_array_2) / sizeof(uint32_t));

	select_sort_int_min_2_max(test_array_1, sizeof(test_array_1) / sizeof(uint32_t));
	select_sort_int_min_2_max(test_array_2, sizeof(test_array_2) / sizeof(uint32_t));

	getchar();
}