 /*  _____                 _
  * |  __ \               | |
  * | |__) |__ _ _ __   __| | ___  _ __ ___
  * |  _  // _` | '_ \ / _` |/ _ \| '_ ` _ \
  * | | \ \ (_| | | | | (_| | (_) | | | | | |
  * |_|__\_\__,_|_| |_|\__,_|\___/|_| |_| |_|
  *  / ____|          | |
  * | (___   ___  _ __| |_ ___ _ __
  *  \___ \ / _ \| '__| __/ _ \ '__|
  *  ____) | (_) | |  | ||  __/ |
  * |_____/ \___/|_|   \__\___|_|  v0.1
  * einKnie@gmx.at
  */
#include "sorter.h"
#include <time.h>

Sorter::Sorter(size_t len) {
  srand(time(NULL));

  m_log = new Logger();
  m_len = len;
  m_indexArray = (int*)malloc(m_len * sizeof(int));

  fillArray();
  m_log->always("New sorter created");
}

Sorter::~Sorter() {
  m_log->always("Exiting...");
  free (m_indexArray);
  delete m_log;
}

unsigned long long Sorter::sort(const int *arr) {
  unsigned long long i = 0;
  while (!isSorted(arr)) {
    fillArray(m_indexArray, m_len, 0, true);
    i++;
  }
  m_log->always("Array is sorted after %ld iterations:", i);
  printArray(arr);
  return i;
}

bool Sorter::isSorted(const int *arr) {
  for (size_t i = 1; i < m_len; i++) {
    if (arr[m_indexArray[i]] < arr[m_indexArray[i-1]]) {
      return false;
    }
  }
  return true;
}

void Sorter::fillArray(int* arr, size_t len, size_t range, bool unique) {
  int *a   = (arr == NULL) ? m_indexArray : arr;
  size_t l = (len == 0)    ? m_len : len;
  size_t r = (range == 0)  ? l     : range;

  for (size_t i = 0; i < l; i++) {
    a[i] = rand() % r;
    if (unique) {
      for (size_t j = 0; j < i; j++) {
        if (a[j] == a[i]) {
          i--;
          break;
        }
      }
    }
  }
  return;
}

void Sorter::printArray(const int *arr) {
  for (size_t i = 0; i < m_len; i++) {
    m_log->info("position %i: %i", m_indexArray[i], arr[m_indexArray[i]]);
  }
}
