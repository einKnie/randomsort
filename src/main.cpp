#include "sorter.h"
#include <stdio.h>

void fillIntArray(int* arr, size_t len, size_t range=0, bool unique=true) {
  size_t r = (range == 0)  ? len : range;

  for (size_t i = 0; i < len; i++) {
    arr[i] = rand() % r;
    if (unique) {
      for (size_t j = 0; j < i; j++) {
        if (arr[j] == arr[i]) {
          i--;
          break;
        }
      }
    }
  }
  return;
}

void fillFloatArray(double* arr, size_t len, size_t range=0, bool unique=true) {
  size_t r = (range == 0)  ? len : range;

  for (size_t i = 0; i < len; i++) {
    arr[i] = ((double)rand() / RAND_MAX) * r;
    if (unique) {
      for (size_t j = 0; j < i; j++) {
        if (arr[j] == arr[i]) {
          i--;
          break;
        }
      }
    }
  }
  return;
}

#define _USE_FLOAT_

int main (int argc, char* argv[]) {

  if (argc < 2) {
    fprintf(stderr, "Needs to be called with array length");
    return 1;
  }

  size_t len = atoi(argv[1]);
  size_t range = (argc > 2) ? atoi(argv[2]) : len;

#ifndef _USE_FLOAT_
  // Integer sorting
  int *arr = (int*)malloc(len * sizeof(int));
  Sorter<int> *sort = new Sorter<int>(len);
  fillIntArray(arr, len, range, true);
  printf("Array is sorted after %llu iterations\n", sort->sort(arr));
  const uint8_t *index = sort->getIndex();

  for (size_t i = 0; i < len; i++) {
    printf("position %d: %d\n", index[i], arr[index[i]]);
  }

#else
  // Double sorting
  double *arr = (double*)malloc(len * sizeof(double));
  Sorter<double> *sort = new Sorter<double>(len);
  fillFloatArray(arr, len, range, true);
  printf("Array is sorted after %llu iterations\n", sort->sort(arr));
  const uint8_t *index = sort->getIndex();

  for (size_t i = 0; i < len; i++) {
    printf("position %d: %.2f\n", index[i], arr[index[i]]);
  }

#endif

  delete sort;
  free(arr);
  return 0;
}
