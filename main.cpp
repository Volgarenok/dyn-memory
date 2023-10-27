#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "matrix.hpp"

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
  using namespace kasilov;
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
