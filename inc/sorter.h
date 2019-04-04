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

#include <stdlib.h>
#include <stdint.h>
#include <time.h>

template <class T> class Sorter {

public:

  Sorter(uint8_t len);
  ~Sorter();

  /// Sort an array \a arr
  /// @return the number of iterations needed
  uint64_t sort(const T* arr);

  /// Return the index array
  const uint8_t* getIndex(void);


private:

  uint8_t  m_len;        ///< array length
  uint8_t *m_index;      ///< index array

  /// Check if array is sorted
  bool isSorted(const T* arr);

  /// Shuffle the index array
  void shuffleIndex(void);

};

template <class T> Sorter<T>::Sorter(uint8_t len) {
  srand(time(NULL));

  m_len = len;
  m_index = (uint8_t*)malloc(m_len * sizeof(uint8_t));

  // Initialize index in default order to catch pre-sorted arrays
  for (uint8_t i = 0; i < m_len; i++) {
    m_index[i] = i;
  }
}

template <class T> Sorter<T>::~Sorter() {
  free(m_index);
}

template <class T> uint64_t Sorter<T>::sort(const T* arr) {
  uint64_t i = 0;
  while (!isSorted(arr)) {
    shuffleIndex();
    i++;
  }
  return i;
}

template <class T> bool Sorter<T>::isSorted(const T* arr) {
  for (uint8_t i = 1; i < m_len; i++) {
    if (arr[m_index[i]] < arr[m_index[i-1]]) {
      return false;
    }
  }
  return true;
}

template <class T> void Sorter<T>::shuffleIndex() {
  for (uint8_t i = 0; i < m_len; i++) {
    m_index[i] = (uint8_t)rand() % m_len;
    for (uint8_t j = 0; j < i; j++) {
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
