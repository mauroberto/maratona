/*
  Sample solution using alice library.
  This solution is incorrect.
  It is provided only to demonstrate the library usage.
 */

#include "alice.h"

int k, m, n;

int main()
{
  n = get_n();
  k = 0;
  while (k == 0 /* condition - k is unknown */) {
    m = 2; /* find somehow m */
    if (is_divisible_by(m))
      k = 2; /* do some action; k is divisible by m */
    else
      k = 1; /* do some action; k is not divisible by m */
  }
  /* here k should be Alice's secret number */
  guess(k);
  return 0;
}
