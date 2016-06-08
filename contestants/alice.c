/* this module can be used for testing your solution */

#include <stdio.h>
#include <stdlib.h>
#include "alice.h"

static int n = 0;

static int l, questions_number;
	
int get_n()
{
  if (n == 0) {
    printf("Input n - the upper bound on the number Alice has to choose: ");
    scanf("%d", &n);
    if (n <= 0) {
      printf("ERROR: n nonpositive\n");
      exit(1);
    }
    printf("Input Alice's secret number: ");
    scanf("%d", &l);
    if (l <= 0 || l > n) {
      printf("ERROR: Alice's number out of bounds\n");
      exit(1);
    }
    questions_number = 0;
  }
  printf("get_n() = %d\n", n);
  return n;
}

int is_divisible_by(int m)
{
  int ans;
  printf("is_divisible_by(%d) ", m);
  if (n == 0) {
    printf("ERROR: "
	   "Function `is_divisible_by' was called before function `get_n'\n");
    exit(1);
  }
  if (m <= 0) {
    printf("ERROR: Function `is_divisible_by' was called with negative m\n");
    exit(1);
  }
  if (m > n) {
    printf("ERROR: Function `is_divisible_by' was called with m > n\n");
    exit(1);
  }
  questions_number++;
  ans = l % m == 0;
  printf("= %d\n", ans);
  return ans;
}
	
void guess(int k)
{
  printf("guess(%d)", k);
  if (n == 0) {
    printf(" ERROR: Function `guess' was called before function `get_n'\n");
    exit(1);
  }

  printf("\nAlice's secret number is %d\n", l);

  if (k != l) {
    printf("FAIL: Alice's secret number is missed after asking %d questions\n",
	   questions_number);
    exit(1);
  }

  printf("SUCCESS: Alice's secret number guessed successively after asking "
	 "%d questions\n", questions_number);
  exit(0);
}
