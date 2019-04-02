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
  * |_____/ \___/|_|   \__\___|_|  v0.2
  * einKnie@gmx.at
  */

#ifndef __RANDOMSORTER_H_
#define __RANDOMSORTER_H_

#include "../libraries/cpp_log.h"
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

template <class T> class Sorter {

public:

  Sorter(size_t len);
  ~Sorter();

  /// Sort an array
  /// @param [in] arr the array to be sorted
  /// @return number of iterations needed for sorting
  unsigned long long sort(const T* arr);

  /// Return the index array
  const uint8_t* getIndex(void);


private:

  Logger  *m_log;        ///< logger
  size_t   m_len;        ///< array length
  uint8_t *m_index;      ///< index array

  /// Check if array is sorted
  /// @param [in] arr the array to check
  /// @return true if sorted, false otherwise
  bool isSorted(const T* arr);

  /// Shuffle the index array
  void shuffleIndex(void);

};

template <class T> Sorter<T>::Sorter(size_t len) {
  srand(time(NULL));

  m_log = new Logger();
  m_len = len;
  m_index = (uint8_t*)malloc(m_len * sizeof(uint8_t));

  // Initialize in default order to catch pre-sorted arrays
  for(size_t i = 0; i < m_len; i++) {
    m_index[i] = i;
  }
  m_log->always("New sorter created");
}

template <class T> Sorter<T>::~Sorter() {
  m_log->always("Exiting...");
  free(m_index);
  delete m_log;
}

template <class T> unsigned long long Sorter<T>::sort(const T* arr) {
  unsigned long long i = 0;
  while (!isSorted(arr)) {
    shuffleIndex();
    i++;
  }
  m_log->always("Array is sorted after %llu iterations:", i);
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
    m_index[i] = (uint8_t)rand() % m_len;
    for (size_t j = 0; j < i; j++) {
      if (m_index[j] == m_index[i]) {
        i--;
        break;
      }
    }
  }
  return;
}

template <class T> const uint8_t* Sorter<T>::getIndex() {
  return (const uint8_t*) m_index;
}

#endif //!__RANDOMSORTER_H_
