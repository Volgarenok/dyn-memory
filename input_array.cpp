#include "input_array.hpp"
#include <algorithm>
#include <iostream>

std::istream & kasilov::inputArray(std::istream & in, int * a, size_t s, size_t toread, size_t & read)
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
size_t kasilov::inputArray(std::istream & in, int * a, size_t s, size_t toread)
{
  size_t read = 0;
  inputArray(in, a, s, toread, read);
  return read;
}
