#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#define HLIMIT 10e-6
#define PI     3.1415926535

double ndersin(double x);
int tcmp(double testVal, double realVal);
int test(double x, size_t count);
void test_suite(void);

// Numerical derivative of sin(x)
double
ndersin(double x)
{
  const long double lx = (long double)x;
  const long double dx = 2 * HLIMIT;
  const long double dy = sinl(lx + HLIMIT) - sinl(lx - HLIMIT);
  const long double fx = dy / dx;
  return (double)fx;
}

int
tcmp(double val, double real)
{
  return (fabs(val - real) < HLIMIT);
}

int
main(void)
{
  test_suite();
  return EXIT_SUCCESS;
}

void test_suite(void) {
  size_t count, pass, fail = 0;
  puts("Begin test suite\n");
  // Test case 1, x = 0;
  count++;
  test(0, count) ? pass++ : fail++;
  // Test case 2, x = pi / 2;
  count++;
  test(PI / 2, count) ? pass++ : fail++;
  puts("Test suite complete");
  printf("Pass: %lx\nFail: %lx\n", pass, fail);
}

int
test(double x, size_t count)
{
  const double tinp = sin(x);
  const double tans = cos(x);
  const double tres = ndersin(x);
  const int pass = tcmp(tres, tans);
  printf("  Test: %lx\t\tx=\t%f\n", count, x);
  printf("\t\tf(x)=sin(x)=\t%f\n", tinp);
  printf("\t\tf'(x)=cos(x)=\t%f\n", tans);
  printf("\t\tnderiv(x)=\t%f\n", tres);
  printf("  Test %lx Pass: %s\n\n", count, pass ? "PASS" : "FAIL");
  return pass; 
}
