// Fibonacci Series using Recursion
#include <stdio.h>
#include <time.h>
long
fib(int n)
{
  if (n <= 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}

int
main()
{
  int n = 50;
  clock_t begin, end;
  double time_spent;

  begin = clock();
  printf("Fibonacci number is %ld\n", fib(n));
  end = clock();

  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("\nTime Taken %lf\n", time_spent);

  return 0;
}
