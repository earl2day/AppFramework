//#include "Trace.hpp"
#include "ConsoleControl.hpp"

Framework::ConsoleControl::ConsoleControl(int argc, char** argv)
 : m_argc(argc), m_argv(argv)
{
// Trace::Log("ConsoleControl::+ConsoleControl");
      
// Trace::Log("ConsoleControl::-ConsoleControl");
}

Framework::ConsoleControl::~ConsoleControl()
{
// Trace::Log("ConsoleControl::+~ConsoleControl");
 
// Trace::Log("ConsoleControl::-~ConsoleControl");
}

unsigned long long Framework::ConsoleControl::GetAddress()
{
 return (unsigned long long)this;
}

