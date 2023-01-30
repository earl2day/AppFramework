#ifndef _FRAMEWORK_CONTROL_HPP_
#define _FRAMEWORK_CONTROL_HPP_

#include "Object.hpp"
#include "View.hpp"
#include "Model.hpp"

namespace Framework
{
class Control : public Object
{
 public:
 	virtual int Bind(Framework::View* view, Framework::Model* model)=0;
};
};

#endif
