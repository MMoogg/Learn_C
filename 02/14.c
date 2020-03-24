#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>


#define MAX_ONE_WORLD_LEN			(30)
#define MAX_READ_ALP_LEN			(MAX_ONE_WORLD_LEN - 1)
#define MAX_COUNT_DIFFERENT_WORLD	(2000)


bool open_read_file(FILE **fp, char const *file_name)
{
	bool ret = false;

	if (file_name != NULL)
	{
		if (fopen_s(fp, file_name, "r") == 0)
		{
			ret = true;
		}
	}
	return ret;
}


void close_read_file(FILE *fp)
{
	fclose(fp);
}


bool open_write_file(FILE **fp, char const *file_name)
{
	bool ret = false;

	if (file_name != NULL)
	{
		if (fopen_s(fp, file_name, "w") == 0)
		{
			ret = true;
		}
	}

	return ret;
}


void write_result_to_file(FILE *fp, char const (*save_buf)[MAX_ONE_WORLD_LEN], uint32_t const *world_freq, uint32_t word_number)
{
	if ( (fp != NULL) && (save_buf != NULL) && (world_freq != NULL) && (word_number > 0) )
	{
		uint32_t i;

		for (i = 0; i < word_number; i++)
		{
			fprintf(fp, "%-30s  :  %4d times\r\n", *(save_buf + i), *(world_freq + i));
		}

		fclose(fp);
	}
}


bool get_one_word_from_file(FILE *read_file, char *read_result)
{
	bool ret = false;
	char ch;
	uint32_t read_len = 0;

	if ( (read_file != NULL) && (read_result != NULL) )
	{
		do
		{
			ch = fgetc(read_file);
		}while ( (ch != EOF) && (!isalpha(ch)) );

		while ( (ch != EOF) && (isalpha(ch)) && (read_len < MAX_READ_ALP_LEN))
		{
			read_result[read_len++] = ch;
			ch = fgetc(read_file);
		}

		if (read_len > 0)
		{
			read_result[read_len] = '\0';
			ret = true;
		}
	}

	return ret;
}


bool find_min_2_max_insert_position(char const (*save_buf)[MAX_ONE_WORLD_LEN], uint32_t save_num, uint32_t *insert_position, char const *insert_buf)
{
	bool ret = false;
	char const (*tmp_p)[MAX_ONE_WORLD_LEN];

	if ( (save_buf != NULL) && (insert_position != NULL) && (insert_buf != NULL) )
	{
		uint32_t i;
		for (i = 0; i < save_num; i++)
		{
			tmp_p = save_buf + i;

			if ( strncmp(*tmp_p, insert_buf, MAX_ONE_WORLD_LEN) > 0 )
			{
				break;
			}
		}
		*insert_position = i;
		ret = true;
	}

	return ret;
}


void move_array_element_one_position(char(*save_buf)[MAX_ONE_WORLD_LEN], int32_t start_index, int32_t end_index)
{
	if ((save_buf != NULL) && (end_index >= start_index))
	{
		int32_t i;
		for (i = end_index; i >= start_index; i--)
		{
			strncpy_s(*(save_buf + i + 1), MAX_ONE_WORLD_LEN, *(save_buf + i), MAX_ONE_WORLD_LEN);
		}
	}
}


void move_int_element_one_position(uint32_t *array, int32_t start_index, int32_t end_index)
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

void insert_one_world_in_buf(char(*save_buf)[MAX_ONE_WORLD_LEN], uint32_t save_num, char const *word_buf, uint32_t *count_result_buf)
{
	uint32_t insert_position = 0;

	if ((save_buf != NULL) && (word_buf != NULL) && (count_result_buf != NULL))
	{
		find_min_2_max_insert_position(save_buf, save_num, &insert_position, word_buf);
		if (insert_position == save_num)
		{
			strncpy_s(*(save_buf + insert_position), MAX_ONE_WORLD_LEN, word_buf, MAX_ONE_WORLD_LEN);
		}
		else
		{
			move_array_element_one_position(save_buf, insert_position, save_num - 1);
			strncpy_s(*(save_buf + insert_position), MAX_ONE_WORLD_LEN, word_buf, MAX_ONE_WORLD_LEN);
			move_int_element_one_position(count_result_buf, insert_position, save_num - 1);

		}
		count_result_buf[insert_position] = 1;
	}
}


bool binary_search_min_2_max(char const (*save_buf)[MAX_ONE_WORLD_LEN], uint32_t save_num, char const *word_buf, uint32_t *result_index)
{
	bool ret = false;
	*result_index = 0;

	if (save_buf != NULL)
	{
		int32_t search_begin = 0, search_end = save_num - 1, search_mid = 0;

		while ((search_begin <= search_end) && (search_begin >= 0) && (search_end >= 0))
		{
			search_mid = (search_begin + search_end) / 2;

			if (strncmp(save_buf[search_mid], word_buf, MAX_ONE_WORLD_LEN) == 0)
			{
				*result_index = search_mid;
				ret = true;
				break;
			}
			else if (strncmp(save_buf[search_mid], word_buf, MAX_ONE_WORLD_LEN) < 0)
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


uint32_t count_world_freq[MAX_COUNT_DIFFERENT_WORLD];
char count_world_buf[MAX_COUNT_DIFFERENT_WORLD][MAX_ONE_WORLD_LEN];
char once_read_word[MAX_ONE_WORLD_LEN];

int main(int argc, char *argv[])
{
	bool ret;
	FILE *read_file_fp, *result_file_fp;
	uint32_t save_world_numbers = 0, saved_index = 0;

	memset(count_world_freq, 0, MAX_COUNT_DIFFERENT_WORLD * sizeof(uint32_t));
	memset(count_world_buf, 0, MAX_COUNT_DIFFERENT_WORLD * MAX_ONE_WORLD_LEN * sizeof(char));

	if (open_read_file(&read_file_fp, "count_word.txt") == false)
	{
		printf("open read input file failed! \r\n");
		return (-1);
	}
	if (open_write_file(&result_file_fp, "count_result.txt") == false)
	{
		printf("open write result file failed! \r\n");
		return (-2);
	}

	do
	{
		ret = get_one_word_from_file(read_file_fp, once_read_word);

		if (ret == true)
		{
			if (binary_search_min_2_max(count_world_buf, save_world_numbers, once_read_word, &saved_index))
			{
				count_world_freq[saved_index]++;
			}
			else
			{
				insert_one_world_in_buf(count_world_buf, save_world_numbers, once_read_word, count_world_freq);
				save_world_numbers++;
			}
		}
	} while ((ret == true) && (save_world_numbers < MAX_COUNT_DIFFERENT_WORLD));

	close_read_file(read_file_fp);
	write_result_to_file(result_file_fp, count_world_buf, count_world_freq, save_world_numbers);

	getchar();
}
