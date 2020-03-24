#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int arg, int *argv[])
{
	int arr[] = { 6,7,8,9,10 };
	int *you = arr;
	*(you++) += 123;
	printf("%d,%d\n", *you, *(++you));

	int guagua = 10;
	printf("%d,%d \n", ++guagua, ++guagua);

	guagua = 10;
	printf("%d,%d \n", (guagua++), (guagua++));

	guagua = 10;
	printf("%d,%d \n", guagua++, guagua++);
}