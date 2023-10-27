#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

void freeMatrix(int ** m, size_t rows)
{
  if (m == nullptr)
  {
    return;
  }
  for (size_t i = 0; i < rows; ++i)
  {
    delete [] m[i];
  }
  delete [] m;
}

int ** createMatrix(size_t rows, size_t cols)
{
  int ** rowsptrs = new int *[rows];
  for (size_t i = 0; i < rows; ++i)
  {
    rowsptrs[i] = nullptr;
  }
  try
  {
    for (size_t i = 0; i < rows; ++i)
    {
      rowsptrs[i] = new int[cols];
    }
    return rowsptrs;
  }
  catch (const std::bad_alloc &)
  {
    freeMatrix(rowsptrs, rows);
    throw;
  }
}

std::istream & inputArray(std::istream & in, int * a, size_t s, size_t toread, size_t & read)
{
  for (size_t i = 0; i < std::min(toread, s); ++i)
  {
    if (!(in >> a[i]))
    {
      read = i;
      return in;
    }
  }
  read = std::min(toread, s);
  return in;
}
size_t inputArray(std::istream & in, int * a, size_t s, size_t toread)
{
  size_t read = 0;
  inputArray(in, a, s, toread, read);
  return read;
}

int main(int argc, char * argv[])
{
  for (int i = 0; i < argc; ++i)
  {
    std::cout << argv[i] << "\n";
  }
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  //argv[1] - число, т.е. номер задания
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 3;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 3;
  }

  //argv[2] - имя файла с матрицей
  size_t rows = 0, cols = 0;
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Cannot read a number\n";
      return 2;
    }
  }
  int * matrix = new int[rows * cols];
  size_t result = inputArray(std::cin, matrix, rows * cols, rows * cols);
  if (!std::cin)
  {
    delete [] matrix;
    return 3;
  }

  int ** rowsptrs = nullptr;
  int ** rowsptrs2 = nullptr;
  try
  {
    //...
    freeMatrix(rowsptrs, rows);
    freeMatrix(rowsptrs2, rows);
  }
  catch (...)
  {
    delete [] matrix;
    freeMatrix(rowsptrs, rows);
    freeMatrix(rowsptrs2, rows);
    std::cerr << "Not enough memory\n";
    return 4;
  }
  delete[] matrix;
  //int * matrix = new int[cols * rows];
  //delete [] matrix;
}
