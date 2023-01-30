#ifndef _FRAMEWORK_MODEL_HPP_
#define _FRAMEWORK_MODEL_HPP_

#include <string>
#include "Object.hpp"
#include "Consts.hpp"

namespace Framework
{
class Model : public Object
{
 public:
 /**
  Return the address of the instance
 */
  unsigned long long GetAddress();
};
};

#endif
