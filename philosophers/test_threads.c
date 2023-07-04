#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void  *routine()
{
  int num;

  num = 33;
  while (num > 0)
  {
    if (num % 2 > 0)
      printf("num !even = [%d]\n", num);
    sleep(3);
    if (num % 2 == 0)
      printf("num even = [%d]\n", num);
    num--;
  }
  return (NULL);
}

int main()
{
  pthread_t t1;
  pthread_t t2;
  pthread_create(&t1, NULL, &routine, NULL);
  pthread_create(&t2, NULL, &routine, NULL);
  pthread_join(t1, NULL);
  return (EXIT_SUCCESS);
}
