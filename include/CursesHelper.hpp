#ifndef _CURSES_HELPER_HPP_
#define _CURSES_HELPER_HPP_

#include <string>

namespace Framework
{
class CursesHelper
{
 public:
  static void PrintStringWithHighlight(std::string dispString);
};
};
#endif
