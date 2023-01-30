#ifndef _TRACE_H_
#define _TRACE_H_

#include <string>

class Trace
{
 public:
  Trace();
  static void Start(std::string className, std::string methodName);
  static void Log(std::string message);
  static void Stop(std::string className, std::string methodName, std::string retVal);
};
#endif
