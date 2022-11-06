#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996) 

int main_2()
{
	char arr[100];
	scanf("%s", arr);
	char halfArr[50] = "";
	while (arr[0] != NULL)
	{
		arr[strlen(arr) / 2] = NULL;
		printf("%s\n", arr);
	}
	return 0;
}
	