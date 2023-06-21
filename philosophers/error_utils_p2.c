#include "philo.h"

void	pth_alc_err(int i)
{
	if (i == 0)
		printf("Thread ids memory allocations failed !\n");
	if (i == 1)
		printf("Fork memory allocations failed !\n");
	if (i == 2)
		printf("Philosophers memory allocations failed !\n");
}