#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996) 

int main_1()
{
	char arr[100];
	scanf("%s", arr);
	char firstHalfArr[50]="";
	strncpy(firstHalfArr, arr, strlen(arr) / 2);
	char secondHalfArr[50]="";
	for (int i = 0; i < strlen(arr)/2; i++)
	{
		secondHalfArr[i] = arr[(strlen(arr) / 2) + i];
	}
	printf("%s\n", firstHalfArr);
	printf("%s", secondHalfArr);


	return 0;
}