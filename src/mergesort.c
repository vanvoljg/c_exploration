/**
 * Merge Sort Algorithm
 */
#include <float.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

int cmp_dbl_arr(double[], double[], size_t);
void mergesort_dbl(double array[], size_t length);
void msdbl_split(double[], int left_idx, int right_idx);
void msdbl_merge(double array[], int left_idx, int mid_idx, int right_idx);
void print_dbl_arr(double array[], size_t length);
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
  int exit = EXIT_SUCCESS;

  printf("Testing array tester\n");
  double T1[] = { 1, 2, 3, 4 };
  double T2[] = { 1, 2, 3, 4 };
  const size_t test_len = sizeof T1 / sizeof T1[0];
  if (!cmp_dbl_arr(T1, T2, test_len)) {
    printf("Yay! Array tester works!\n");
  } else {
    printf("No.\n");
    exit = EXIT_FAILURE;
  }

  printf("TESTING MERGE SORT!\n");
  double Unsorted[] = { 8, 2, 9, 5.5, 1, 15, 4 };
  double Sorted[] = { 1, 2, 4, 5.5, 8, 9, 15 };
  const size_t len = sizeof Unsorted / sizeof Unsorted[0];
  mergesort_dbl(Unsorted, len);
  if (!cmp_dbl_arr(Unsorted, Sorted, len)) {
    printf("  Mergesort success\n");
  } else {
    printf("  Mergesort failure :-(\n");
    exit = EXIT_FAILURE;
  }

  printf("Testing empty array\n");
  double empty1[0];
  double empty2[0];
  const size_t empty_len = sizeof empty1 / sizeof empty1[0];
  mergesort_dbl(empty1, 0);
  if (!cmp_dbl_arr(empty1, empty2, empty_len)) {
    printf("  Success\n");
  } else {
    printf("  Failure\n");
    exit = EXIT_FAILURE;
  }

  printf("Testing array with negative numbers\n");
  double neg1[] = { 4, -1, -9, 2, 0 };
  double neg2[] = { -9, -1, 0, 2, 4 };
  const size_t neg_len = sizeof neg1 / sizeof neg1[0];
  mergesort_dbl(neg1, neg_len);
  if (!cmp_dbl_arr(neg1, neg2, neg_len)) {
    printf("  Success\n");
  } else {
    printf("  Failure\n");
    exit = EXIT_FAILURE;
  }

  return exit;
}

void
mergesort_dbl(double unsorted[], size_t len)
{
  if (len < 2) {
    return;
  }
  const size_t l_idx = 0;
  const size_t r_idx = len - 1;
  msdbl_split(unsorted, l_idx, r_idx);
  return;
}

void
msdbl_split(double arr[], int l_idx, int r_idx)
{
  if (l_idx < r_idx) {
    const size_t len = r_idx - l_idx + 1;
    const int mid = ((len + 1) >> 1) + l_idx;

    msdbl_split(arr, l_idx, mid - 1);
    msdbl_split(arr, mid, r_idx);

    msdbl_merge(arr, l_idx, mid, r_idx);
  }
  return;
}

void
msdbl_merge(double arr[], int l_Idx, int m_idx, int r_idx)
{
  const size_t len = r_idx - l_Idx + 1;
  int left = l_Idx;
  int right = m_idx;

  // Merge the given sorted runs into a temp array
  double tmp[len];
  int out_idx = 0;
  for (int i = 0; i < len; i++) {
    if (left >= m_idx) {
      tmp[i] = arr[right];
      right++;
    } else if (right > r_idx) {
      tmp[i] = arr[left];
      left++;
    } else if (arr[left] <= arr[right]) {
      tmp[i] = arr[left];
      left++;
    } else if (arr[left] > arr[right]) {
      tmp[i] = arr[right];
      right++;
    }
  }

  // Copy all the values back into the array
  for (int i = 0; i < len; i++) {
    arr[l_Idx + i] = tmp[i];
  }

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
};

void
print_dbl_arr(double arr[], size_t len)
{
  printf("[\n");
  for (int i = 0; i < len; i++) {
    printf("  %f,\n", arr[i]);
  }
  printf("]\n");
}
