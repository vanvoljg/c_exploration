/* C program for Tabulated version */
#include <stdio.h>
#include <time.h>
#include <limits.h>

unsigned long long
fib(int n)
{
  unsigned long long f[n + 1];
  int i;

  f[0] = 0;
  f[1] = 1;
  for (i = 2; i <= n; i++)
    f[i] = f[i - 1] + f[i - 2];

  return f[n];
}

int
main()
{
  int n = 103;
  clock_t begin, end;
  double time_spent;

  begin = clock(); // Time before calculating Fib number
  printf("maxint: \t\t%llu\n", ULLONG_MAX);
  printf("Fibonacci number is \t%llu\n", fib(n));
  end = clock(); // Time before calculating Fib number

  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("\nTime Taken %lf\n", time_spent);

  return 0;
}
