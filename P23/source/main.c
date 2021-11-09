#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status {CONTINUE,WON,LOST};
int rollDice(void);

int main(void)
{
	int sum;
	int mypoint;

	enum Status gamestatus;

	srand(time(NULL));
	sum = rollDice();

	switch (sum)
	{
	case 7:
	case 11:
		gamestatus = WON;
		break;
	case 2:
	case 3:
	case 12:
		gamestatus = CONTINUE;
		break;

	default:
		gamestatus = CONTINUE;
		mypoint = sum;
		printf("Point is %d\n", mypoint);
		break;
	}

	while (gamestatus == CONTINUE)
	{
		sum = rollDice();
		if (sum == mypoint)
		{
			gamestatus = WON;
		}
		else
		{
			if (sum == 7)
			{
				gamestatus = LOST;
			}
		}
	}

	if (gamestatus == WON)
	{
		printf("Player wins\n");
	}
	else
	{
		printf("Palyer loses\n");
	}
	system("pause");
	return 0;
}

int rollDice(void)
{
	int d1;
	int d2;
	int work;

	d1 = 1 + (rand() % 6);
	d2 = 1 + (rand() % 6);
	work = d1 + d2;
	printf("Player rolled %d +%d = %d\n", d1, d2, work);
	return work;
}