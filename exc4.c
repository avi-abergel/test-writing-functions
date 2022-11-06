#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996) 

typedef struct lottery_t {
	char numLottery [100];
	char date [100];
	struct lottery_t* prev;
	struct lottery_t* next;
}lottery;

lottery* head = NULL;
lottery* tail = NULL;

lottery* lotteryHistory(char fileName[100])
{
	FILE* f = fopen(fileName, "r");
	if (!f)
	{
		printf("ERROR! file not found");
		return;
	}
	else {
		char buffer[100];
		while (fgets(buffer, 100, f) != NULL)
		{
			lottery* newLottery = (lottery*)malloc(sizeof(lottery));
			char* token = strtok(buffer, ",");
			strcpy(newLottery->numLottery, token);
			token = strtok(NULL, ",");
			strcpy(newLottery->date, token);
			if (head == NULL)
			{
				head = newLottery;
				tail = newLottery;
				newLottery->prev = NULL;
				newLottery->next = NULL;
			}
			else {
				tail->next = newLottery;
				newLottery->prev = tail;
				tail = newLottery;
				newLottery->next = NULL;
			}
		}
	}

}

char* searchLottery(char lotteryNum[4])
{
	lottery* index = head;
	while (index != NULL)
	{
		if (strcmp(index->numLottery,lotteryNum)==0)
			return index->date;
		index = index->next;
	}
}

int main()
{
	lotteryHistory("C:\\Users\\97252\\source\\repos\\test- writing functions\\test- writing functions\\Lotto.txt");
	printf("choose an option:\n N-saerch a lottery with lottery code\n Q-quit\n");
	char userResponse;
	scanf("%c", &userResponse);
	if (userResponse == 'N')
	{
		printf("please enter a lottery code\n");
		char code[4];
		scanf("%s", code);
		printf(searchLottery(code));
	}
	else {
		printf("GOODBYE!");
		while (head != NULL)
		{
			lottery* index = head;
			head = head->next;
			free (index);
		}
			
	}

	
	return 0;
}