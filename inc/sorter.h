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

#ifndef __RANDOMSORTER_H_
#define __RANDOMSORTER_H_

#include "../libraries/cpp_log.h"
#include <stdlib.h>
#include <time.h>

template <class T> class Sorter {

public:

  Sorter(size_t len);
  ~Sorter();

  /// Sort an array
  /// @param [in] arr the array to be sorted
  /// @return number of iterations needed for sorting
  unsigned long long sort(const T* arr);

  /// Check if array is sorted
  /// @param [in] arr the array to check
  /// @return true if sorted, false otherwise
  bool isSorted(const T* arr);


private:

  Logger *m_log;        ///< logger
  size_t  m_len;        ///< array length
  int    *m_index;      ///< index array

  /// Print the array in order of m_index
  /// @param [in] arr the array to print
  void printArray(const T* arr);

  void shuffleIndex();

};

template <class T> Sorter<T>::Sorter(size_t len) {
  srand(time(NULL));

  m_log = new Logger();
  m_len = len;
  m_index = (int*)malloc(m_len * sizeof(int));

  // Initialize in default order to catch pre-sorted arrays
  for(size_t i = 0; i < m_len; i++) {
    m_index[i] = i;
  }
  m_log->always("New sorter created");
}

template <class T> Sorter<T>::~Sorter() {
  m_log->always("Exiting...");
  free (m_index);
  delete m_log;
}

template <class T> unsigned long long Sorter<T>::sort(const T* arr) {
  unsigned long long i = 0;
  while (!isSorted(arr)) {
    shuffleIndex();
    i++;
  }
  m_log->always("Array is sorted after %ld iterations:", i);
  printArray(arr);
  return i;
}

template <class T> bool Sorter<T>::isSorted(const T* arr) {
  for (size_t i = 1; i < m_len; i++) {
    if (arr[m_index[i]] < arr[m_index[i-1]]) {
      return false;
    }
  }
  return true;
}

template <class T> void Sorter<T>::shuffleIndex() {
  for (size_t i = 0; i < m_len; i++) {
    m_index[i] = rand() % m_len;
    for (size_t j = 0; j < i; j++) {
      if (m_index[j] == m_index[i]) {
        i--;
        break;
      }
    }
  }
  return;
}

template <class T> void Sorter<T>::printArray(const T* arr) {
  for (size_t i = 0; i < m_len; i++) {
    m_log->info("position %i: %i", m_index[i], arr[m_index[i]]);
  }
}

#endif //!__RANDOMSORTER_H_
