/* C program for Tabulated version */
#include <limits.h>
#include <stdio.h>
#include <time.h>

long long unsigned
fact(int n)
{
  long long unsigned fact[n + 1];

  fact[0] = 1;

  for (unsigned i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
  }

  return fact[n - 1];
}

int
main()
{
  int n = 22;
  clock_t begin, end;
  double time_spent;

  begin = clock(); // Time before calculating Fib number
  printf("maxint: \t%llu\n", ULLONG_MAX);
  printf("%d! is: \t%llu\n", n, fact(n));
  end = clock(); // Time before calculating Fib number

  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("\nTime Taken %lf\n", time_spent);

  return 0;
}
