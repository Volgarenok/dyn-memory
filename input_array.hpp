#ifndef INPUT_ARRAY_HPP
#define INPUT_ARRAY_HPP
#include <iosfwd>
namespace kasilov
{
  size_t inputArray(std::istream & in, int * a, size_t s, size_t toread);
  std::istream & inputArray(std::istream & in, int * a, size_t s, size_t toread, size_t & read);
}
#endif
