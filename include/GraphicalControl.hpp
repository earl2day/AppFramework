#ifndef _GRAPHICAL_CONTROL_
#define _GRAPHICAL_CONTROL_

#include "View.hpp"
#include "Model.hpp"
#include "Control.hpp"


namespace Framework
{
class GraphicalControl : public Framework::Control
{
 public:
  GraphicalControl();
  ~GraphicalControl();
  unsigned long long GetAddress();
};
};
#endif
