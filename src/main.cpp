#include "sorter.h"
#include <stdio.h>

void fillIntArray(int* arr, uint8_t len, uint8_t range=0, bool unique=true) {
  uint8_t r = ((range == 0) || (range < len)) ? len : range;

  for (uint8_t i = 0; i < len; i++) {
    arr[i] = rand() % r;
    if (unique) {
      for (uint8_t j = 0; j < i; j++) {
        if (arr[j] == arr[i]) {
          i--;
          break;
        }
      }
    }
  }
  return;
}

void fillFloatArray(double* arr, uint8_t len, uint8_t range=0, bool unique=true) {
  uint8_t r = ((range == 0) || (range < len)) ? len : range;

  for (uint8_t i = 0; i < len; i++) {
    arr[i] = ((double)rand() / RAND_MAX) * r;
    if (unique) {
      for (uint8_t j = 0; j < i; j++) {
        if (arr[j] == arr[i]) {
          i--;
          break;
        }
      }
    }
  }
  return;
}

// #define _USE_FLOAT_

int main (int argc, char* argv[]) {

  if (argc < 2) {
    fprintf(stderr, "Needs to be called with array length");
    return 1;
  }

  uint8_t len = atoi(argv[1]);
  uint8_t range = (argc > 2) ? atoi(argv[2]) : len;

#ifndef _USE_FLOAT_
  // Integer sorting
  int *arr = (int*)malloc(len * sizeof(int));
  Sorter<int> *sort = new Sorter<int>(len);
  fillIntArray(arr, len, range, true);
  printf("Array is sorted after %lu iterations\n", sort->sort(arr));
  const uint8_t *index = sort->getIndex();

  for (uint8_t i = 0; i < len; i++) {
    printf("position %d: %d\n", index[i], arr[index[i]]);
  }

#else
  // Double sorting
  double *arr = (double*)malloc(len * sizeof(double));
  Sorter<double> *sort = new Sorter<double>(len);
  fillFloatArray(arr, len, range, true);
  printf("Array is sorted after %lu iterations\n", sort->sort(arr));
  const uint8_t *index = sort->getIndex();

  for (uint8_t i = 0; i < len; i++) {
    printf("position %d: %.2f\n", index[i], arr[index[i]]);
  }

#endif

  delete sort;
  free(arr);
  return 0;
}
