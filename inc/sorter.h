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

class Sorter {

public:

  Sorter(size_t len);
  ~Sorter();

  /// Fill an array with random data
  /// @param [in,out] arr the array to be filled. use m_indexArray id NULL
  /// @param [in] len length of the array. use m_len if 0
  /// @param [in] range max number to fill array with. use m_len if 0
  /// @param [in] unique do not reuse numbers
  void fillArray(int* arr=NULL, size_t len=0, size_t range=0, bool unique=true);

  /// Sort an array
  /// @param [in] arr the array to be sorted
  /// @return number of iterations needed for sorting
  unsigned long long sort(const int *arr);

  /// Check if array is sorted
  /// @param [in] arr the array to check
  /// @return true if sorted, false otherwise
  bool isSorted(const int *arr);


private:

  Logger *m_log;        ///< logger
  size_t  m_len;        ///< array length
  int    *m_indexArray; ///< index array

  /// Print the array in order of m_indexArray
  /// @param [in] arr the array to print
  void printArray(const int *arr);

};

#endif //!__RANDOMSORTER_H_
