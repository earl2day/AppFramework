#ifndef _CONSOLE_CONTROL_
#define _CONSOLE_CONTROL_

#include "Control.hpp"

namespace Framework
{
class ConsoleControl : public Framework::Control
{
 public:
  	ConsoleControl(int argc, char** argv);
  	~ConsoleControl();
  	unsigned long long GetAddress();
 private:
      	int m_argc;
      	char** m_argv;
};
};
#endif
