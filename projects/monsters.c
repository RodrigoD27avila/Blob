#include <stdio.h>

#define MONSTER_ACTIONS 4

typedef void (*monster[MONSTER_ACTIONS])(void);

void move()
{
	printf("Move\n");
}

void attack()
{
	printf("Attack\n");
}

void cure()
{
	printf("Cure\n");
}

void run()
{
	printf("Run\n");
}


int main()
{
	monster m = {
		move,
		attack,
		cure,
		run,
	};

	int i;
	for (i=0; i<MONSTER_ACTIONS; i++) {
		m[i]();
	}

}
