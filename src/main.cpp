#include "sorter.h"

void fillArray(int* arr, size_t len, size_t range=0, bool unique=true) {
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

int main (int argc, char* argv[]) {

  if (argc < 2) {
    fprintf(stderr, "Needs to be called with array length");
    return 1;
  }

  size_t len = atoi(argv[1]);
  size_t range = (argc > 2) ? atoi(argv[2]) : len;
  int *sArr = (int*)malloc(len * sizeof(int));

  Sorter<int> *sort = new Sorter<int>(len);
  fillArray(sArr, len, range, true);
  sort->sort(sArr);

  delete sort;
  free(sArr);
  return 0;
}
