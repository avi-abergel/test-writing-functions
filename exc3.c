#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996) 

int printNum(int num)
{
	printf("%d\n", num);
	return num == 100 ? 0 : printNum(num + 1);
}

int main_3()
{
	printNum(1);
	return 0;
}