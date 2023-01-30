#ifndef _FRAMEWORK_VIEW_HPP_
#define _FRAMEWORK_VIEW_HPP_

#include "Consts.hpp"
#include "Object.hpp"

namespace Framework
{
class View : public Object
{
 public:
  View();
  ~View();
  unsigned long long GetAddress();
};
};

#endif
