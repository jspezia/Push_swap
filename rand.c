#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	int nb;

	for(i=0; i<2000; i++)
	{
		nb = rand();
		printf("%d ", nb);
	}
	return 0;
}
