#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
namespace kasilov
{
  void freeMatrix(int ** m, size_t rows, size_t cols);
  void freeMatrix(int ** m, size_t rows);
  int ** createMatrix(size_t rows, size_t cols);
}
#endif
