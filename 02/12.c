#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>


bool find_min_2_max_insert_position(uint32_t *array, uint32_t len, uint32_t *insert_position, uint32_t insert_value)
{
	bool ret = false;

	if ((array != NULL) && (insert_position != NULL) && (len > 0))
	{
		uint32_t i;
		for (i = 0; i < len; i++)
		{
			if (array[i] > insert_value)
			{
				break;
			}
		}
		*insert_position = i;
		ret = true;
	}
	return ret;
}


bool find_max_2_min_insert_position(uint32_t *array, uint32_t len, uint32_t *insert_position, uint32_t insert_value)
{
	bool ret = false;

	if ((array != NULL) && (insert_position != NULL) && (len > 0))
	{
		uint32_t i;
		for (i = 0; i < len; i++)
		{
			if (array[i] < insert_value)
			{
				break;
			}
		}
		*insert_position = i;
		ret = true;
	}
	return ret;
}


void move_array_element_one_position(uint32_t *array, int32_t start_index, int32_t end_index)
{
	if ((array != NULL) && (end_index >= start_index))
	{
		int32_t i;
		for (i = end_index; i >= start_index; i--)
		{
			array[i + 1] = array[i];
		}
	}
}


bool insert_sort_max_2_min(uint32_t *array, uint32_t len)
{
	bool ret = false;

	if ((array != NULL) && (len > 1))
	{
		uint32_t *copy_array = (uint32_t *)malloc(len * sizeof(uint32_t));
		if (copy_array != NULL)
		{
			uint32_t copy_array_len = 1, position;

			copy_array[0] = array[0];

			for (copy_array_len = 1; copy_array_len < len; copy_array_len++)
			{
				find_max_2_min_insert_position(copy_array, copy_array_len, &position, array[copy_array_len]);

				if (position == copy_array_len)
				{
					copy_array[copy_array_len] = array[copy_array_len];
				}
				else
				{
					move_array_element_one_position(copy_array, position, copy_array_len - 1);
					copy_array[position] = array[copy_array_len];
				}
			}

			memcpy(array, copy_array, len * sizeof(uint32_t));
			free(copy_array);

			ret = true;
		}
	}
	return ret;
}

bool insert_sort_min_2_max(uint32_t *array, uint32_t len)
{
	bool ret = false;

	if ((array != NULL) && (len > 1))
	{
		uint32_t *copy_array = (uint32_t *)malloc(len * sizeof(uint32_t));
		if (copy_array != NULL)
		{
			uint32_t copy_array_len = 1, position;

			copy_array[0] = array[0];

			for (copy_array_len = 1; copy_array_len < len; copy_array_len++)
			{
				find_min_2_max_insert_position(copy_array, copy_array_len, &position, array[copy_array_len]);

				if (position == copy_array_len)
				{
					copy_array[copy_array_len] = array[copy_array_len];
				}
				else
				{
					move_array_element_one_position(copy_array, position, copy_array_len - 1);
					copy_array[position] = array[copy_array_len];
				}
			}

			memcpy(array, copy_array, len * sizeof(uint32_t));
			free(copy_array);

			ret = true;
		}

	}
	return ret;
}

bool add_one_item_min_2_max_array(uint32_t const *array, uint32_t total_len, uint32_t item, uint32_t *result_array)
{
	bool ret = false;

	if (array != NULL)
	{
		if (result_array != NULL)
		{
			int32_t i;
			memcpy(result_array, array, total_len * sizeof(uint32_t));

			for (i = total_len - 1; i >= 0; i--)
			{
				if (result_array[i] > item)
				{
					result_array[i + 1] = result_array[i];
				}
				else
				{
					break;
				}
			}
			result_array[i + 1] = item;
			ret = true;
		}
	}
	return ret;
}


bool add_one_item_max_2_min_array(uint32_t const *array, uint32_t total_len, uint32_t item, uint32_t *result_array)
{
	bool ret = false;

	if (array != NULL)
	{
		if (result_array != NULL)
		{
			int32_t i;
			memcpy(result_array, array, total_len * sizeof(uint32_t));

			for (i = total_len - 1; i >= 0; i--)
			{
				if (result_array[i] < item)
				{
					result_array[i + 1] = result_array[i];
				}
				else
				{
					break;
				}
			}
			result_array[i + 1] = item;
			ret = true;
		}
	}
	return ret;
}


static uint32_t test_array_1[] = { 172, 234, 8909, 239982, 1, 8989 };
static uint32_t test_array_2[] = { 1, 323, 234, 5332, 28109 };


int main(int argc, char *argv[])
{
	uint32_t add_new_item_array_1[20], add_new_item_array_2[20];

	insert_sort_max_2_min(test_array_1, sizeof(test_array_1) / sizeof(uint32_t));
	insert_sort_max_2_min(test_array_2, sizeof(test_array_2) / sizeof(uint32_t));

	add_one_item_max_2_min_array(test_array_2, sizeof(test_array_2) / sizeof(uint32_t), 333333, add_new_item_array_1);
	add_one_item_max_2_min_array(test_array_2, sizeof(test_array_2) / sizeof(uint32_t), 0, add_new_item_array_1);
	add_one_item_max_2_min_array(test_array_2, sizeof(test_array_2) / sizeof(uint32_t), 555, add_new_item_array_1);

	insert_sort_min_2_max(test_array_1, sizeof(test_array_1) / sizeof(uint32_t));
	insert_sort_min_2_max(test_array_2, sizeof(test_array_2) / sizeof(uint32_t));

	add_one_item_min_2_max_array(test_array_1, sizeof(test_array_1) / sizeof(uint32_t), 333333, add_new_item_array_2);
	add_one_item_min_2_max_array(test_array_1, sizeof(test_array_1) / sizeof(uint32_t), 0, add_new_item_array_2);
	add_one_item_min_2_max_array(test_array_1, sizeof(test_array_1) / sizeof(uint32_t), 555, add_new_item_array_2);

	getchar();
}