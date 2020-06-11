/**
 * Quick Sort Algorithm
 */
#include <float.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

int cmp_dbl_arr(double A[], double B[], size_t length);
void print_dbl_arr(double array[], size_t length);
void print_int_arr(int array[], int length);
void print_size_t_arr(size_t array[], size_t length);
void quicksort_dbl(double array[], size_t length);
void qsdbl_split(double array[], int left_idx, int right_idx);
void qsdbl_sort(double array[], int left_idx, int right_idx, int new_idx[]);
void swap_double(double array[], int indexA, int indexB);
int test();

int
main()
{
  if (!test()) {
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}

int
test()
{
  printf("Testing array tester\n");
  double T1[] = { 1, 2, 3, 4 };
  double T2[] = { 1, 2, 3, 4 };
  const size_t test_len = sizeof T1 / sizeof T1[0];
  if (!cmp_dbl_arr(T1, T2, test_len)) {
    printf("  Yay! Array tester works!\n");
  } else {
    printf("  No.\n");
    return EXIT_FAILURE;
  }

  printf("Testing swap_double()\n");
  double sw0[] = { 1, 2 };
  double sw1[] = { 2, 1 };
  const size_t sw_len = sizeof sw0 / sizeof sw0[0];
  swap_double(sw0, 0, 1);
  if (!cmp_dbl_arr(sw0, sw1, sw_len)) {
    printf("  Success\n");
  } else {
    printf("  Failure\n");
    return EXIT_FAILURE;
  }

  printf("TESTING QUICK SORT!\n");
  printf("Testing empty array\n");
  double empty1[0];
  double empty2[0];
  const size_t empty_len = sizeof empty1 / sizeof empty1[0];
  quicksort_dbl(empty1, 0);
  if (!cmp_dbl_arr(empty1, empty2, empty_len)) {
    printf("  Success\n");
  } else {
    printf("  Failure\n");
    return EXIT_FAILURE;
  }

  printf("Testing single-item array\n");
  double single1[] = { 1 };
  double single2[] = { 1 };
  const size_t single_len = sizeof single1 / sizeof single1[0];
  quicksort_dbl(empty1, 0);
  if (!cmp_dbl_arr(empty1, empty2, empty_len)) {
    printf("  Success\n");
  } else {
    printf("  Failure\n");
    return EXIT_FAILURE;
  }

  printf("Testing two-item array\n");
  double two_item1[] = { 3, 2 };
  double two_item2[] = { 2, 3 };
  double two_len = sizeof two_item1 / sizeof two_item1[0];
  quicksort_dbl(two_item1, two_len);
  if (!cmp_dbl_arr(two_item1, two_item2, two_len)) {
    printf("  Success\n");
  } else {
    printf("  Failure\n");
    print_dbl_arr(two_item1, two_len);
    return EXIT_FAILURE;
  }

  printf("Testing all-positive array\n");
  double Unsorted[] = { 8, 2, 9, 5.5, 1, 15, 4 };
  double Sorted[] = { 1, 2, 4, 5.5, 8, 9, 15 };
  const size_t len = sizeof Unsorted / sizeof Unsorted[0];
  quicksort_dbl(Unsorted, len);
  if (!cmp_dbl_arr(Unsorted, Sorted, len)) {
    printf("  Success\n");
  } else {
    printf("  Failure :-(\n");
    return EXIT_FAILURE;
  }

  printf("Testing array with negative numbers\n");
  double negu[] = { 4, -1, -9, 2, 0 };
  double negs[] = { -9, -1, 0, 2, 4 };
  const size_t neg_len = sizeof negu / sizeof negu[0];
  quicksort_dbl(negu, neg_len);
  if (!cmp_dbl_arr(negu, negs, neg_len)) {
    printf("  Success\n");
  } else {
    printf("  Failure\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

void
quicksort_dbl(double array[], size_t len)
{
  if (len < 2) {
    return;
  }
  const int left_idx = 0;
  const int right_idx = len - 1;
  qsdbl_split(array, left_idx, right_idx);
  return;
}

void
qsdbl_split(double arr[], int l_idx, int r_idx)
{
  int new_idx[1];
  qsdbl_sort(arr, l_idx, r_idx, new_idx);

  if (r_idx - l_idx > 2) {
    qsdbl_split(arr, l_idx, new_idx[0] - 1);
    qsdbl_split(arr, new_idx[0], r_idx);
  }
  return;
}

void
qsdbl_sort(double arr[], int l_idx, int r_idx, int new_idx[])
{
  int high_idx = r_idx;
  const double pivot = arr[r_idx];

  int i = l_idx;
  while (i < high_idx) {
    if (arr[i] > pivot) {
      swap_double(arr, i, high_idx);
      high_idx--;
    } else {
      i++;
    }
  }

  new_idx[0] = high_idx;
  return;
}

int
cmp_dbl_arr(double A[], double B[], size_t len)
{
  for (int i = 0; i < len; i++) {
    if (fabs(A[i] - B[i]) > DBL_MIN) {
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}

void
print_dbl_arr(double arr[], size_t len)
{
  printf("[\n");
  for (int i = 0; i < len; i++) {
    printf("  %f,\n", arr[i]);
  }
  printf("]\n");
  return;
}

void
print_size_t_arr(size_t arr[], size_t len)
{
  printf("[\n");
  for (int i = 0; i < len; i++) {
    printf("  %zu,\n", arr[i]);
  }
  printf("]\n");
  return;
}

void
print_int_arr(int arr[], int len)
{
  printf("[\n");
  for (int i = 0; i < len; i++) {
    printf("  %d,\n", arr[i]);
  }
  printf("]\n");
  return;
}

void
swap_double(double arr[], int idx_a, int idx_b)
{
  if (idx_a == idx_b) {
    return;
  }
  double tmp = arr[idx_a];
  arr[idx_a] = arr[idx_b];
  arr[idx_b] = tmp;
  return;
}
