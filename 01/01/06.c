#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>

int main(int arg, int *argv[])
{
	int32_t array_len = 0;
	int32_t *array_buf = NULL;
	int32_t i;
	int32_t tmp_max, tmp_min;

	while (1)
	{
		printf("Input the int array length, within 50£º\r\n");
		scanf_s("%d", &array_len);

		if ((array_len <= 0) || (array_len > 50))
		{
			printf("array len must less than 50 and a postive number \r\n");
		}
		else
		{
			break;
		}
	}



	array_buf = (int32_t *)malloc(array_len * sizeof(int32_t));
	if (array_buf != NULL)
	{
		for (i = 0; i < array_len; i++)
		{
			printf("Input %d number:  ", i + 1);
			scanf_s("%d", array_buf + i);
		}
		printf("Input Over !");

		tmp_max = array_buf[0];
		tmp_min = array_buf[0];

		for (i = 1; i < array_len; i++)
		{
			if (tmp_max < array_buf[i])
			{
				tmp_max = array_buf[i];
			}

			if (tmp_min > array_buf[i])
			{
				tmp_min = array_buf[i];
			}
		}

		printf("MAX number in array is %d \r\n", tmp_max);
		printf("MIN number in array is %d \r\n", tmp_min);

		free(array_buf);
		array_buf = NULL;
	}
	else
	{
		printf("Program error !");
	}



}