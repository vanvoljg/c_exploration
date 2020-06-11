/* Sorting algorithms
 * Author: Jesse Van Volkinburg
 */
#include <inttypes.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

int
main()
{
  int64_t t = INT64_MAX;
  uint64_t m = UINT64_MAX;
  size_t sm = SIZE_MAX;
  int intmax = INT_MAX;

  printf("INT_MAX: %d\n", intmax);
  printf("LLONG_MAX: %" PRId64 "\n", t);
  printf("ULLONG_MAX: %" PRIu64 "\n", m);
  printf("SIZE_MAX: %zu\n", sm);
  /*
  enum corvid {
    magpie,
    raven,
    jay,
    jackdaw,
    crow,
    rook,
    cough,
    corvid_num,
  };

#define CORVID_NAME [><]                                                      \
  (char const* const[corvid_num])                                             \
  {                                                                           \
    [cough] = "cough", [raven] = "raven", [magpie] = "magpie", [jay] = "jay", \
    [rook] = "rook", [crow] = "crow", [jackdaw] = "jackdaw",                  \
  }

  for (unsigned i = 0; i < corvid_num; i++) {
    printf("Corvid %u is the %s\n", i, CORVID_NAME[i]);
  }
  char const* sign_rep[4] = {
    [1] = "sign and magnitude",
    [2] = "ones' complement",
    [3] = "two's complement",
    [0] = "weird",
  };
  enum {
    sign_magic = -1 & 3,
  };
  printf("Sign representation: %s.\n", sign_rep[sign_magic]);
  */

  return EXIT_SUCCESS;
}
