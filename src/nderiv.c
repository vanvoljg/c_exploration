#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

#define HLIMIT 10e-6

double long nderiv(double x);

double long
nderiv(double x)
{
  return 0;
};

int
main(void)
{
  const double t1x = 0.5;
  const double long t1in = sin(t1x);
  const double long t1out = cos(t1x);

  return EXIT_SUCCESS;
};
