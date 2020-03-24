#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct node_inf
{
	uint32_t node_number;
	struct node_inf *p_next_node;
}NODE_INF;

bool format_game_node_circle_list(NODE_INF **head, uint32_t node_number)
{
	bool ret = true;
	uint32_t i = 0;
	NODE_INF *tmp, *last;

	*head = NULL;

	for (i = 0; i < node_number; i++)
	{
		tmp = (NODE_INF *)malloc(sizeof(NODE_INF));

		if (tmp != NULL)
		{
			tmp->node_number = i + 1;
			if (*head == NULL)
			{
				last = tmp;
				*head = tmp;
				tmp->p_next_node = tmp;
			}
			else
			{
				tmp->p_next_node = *head;
				last->p_next_node = tmp;
			}
		}
		else
		{
			ret = false;
			break;
		}
	}
	return ret;
}

void distory_game_node_circle_list(NODE_INF **head)
{
	*head = NULL;
}

bool delete_one_node_from_game_list(NODE_INF *head, uint32_t number)
{
	bool ret = false;
	if (head != NULL)
	{
		NODE_INF *p_tmp_node = head;
		NODE_INF *p_last_node = head;

		while (p_tmp_node->p_next_node != head)
		{
			if (p_tmp_node->node_number == number)
			{
				p_last_node->p_next_node = p_tmp_node->p_next_node;
				break;
			}
			else
			{
				p_last_node = p_tmp_node;
				p_tmp_node = p_tmp_node->p_next_node;
			}
		}

	}
	return ret;
}

NODE_INF *using_number_find_node(NODE_INF *head, uint32_t number)
{
	NODE_INF *ret_node = NULL;
	if (head != NULL)
	{
		NODE_INF *p_tmp_node = head;

		while (p_tmp_node->p_next_node != head)
		{
			if (p_tmp_node->node_number == number)
			{
				ret_node = p_tmp_node;
				break;
			}
			else
			{
				p_tmp_node = p_tmp_node->p_next_node;
			}
		}

	}
	return ret_node;
}

uint32_t game_start(NODE_INF *head, uint32_t start_number)
{
	uint32_t i = 0;
	NODE_INF *tmp;



	while (head->p_next_node != head)
	{
		i = 3;
		while (i)
		{
			
			i--;
		}
		
	}
}

int main(int argc, char *argv[])
{
	uint32_t node_number, start_node;
	NODE_INF *head = NULL;

	printf("Game Begin, input Game Argument:\r\n");

	do
	{
		scanf_s("Input People Number: %d", &node_number);
		scanf_s("Input First Start Node: %d", &start_node);
	} while ( (node_number <= 0) || (start_node > node_number) );

	if (format_game_node_circle_list(&head, node_number))
	{
		game_start(head, start_node);
	}
	else
	{
		printf("Game Start Error !\r\n");
	}
}
