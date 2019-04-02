#include "sorter.h"

int main (int argc, char* argv[]) {

  if (argc < 2) {
    fprintf(stderr, "Needs to be called with array length");
    return 1;
  }

  size_t len = atoi(argv[1]);
  size_t range = (argc > 2) ? atoi(argv[2]) : len;
  int *sArr = (int*)malloc(len * sizeof(int));

  Sorter *sort = new Sorter(len);
  sort->fillArray(sArr, len, range, true);
  sort->sort(sArr);

  delete sort;
  free(sArr);
  return 0;
}
