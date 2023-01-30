#ifndef _LAZY_STRING_CIRCULAR_BUFFER_H_
#define _LAZY_STRING_CIRCULAR_BUFFER_H_

#include <string>

class LazyStringCircularBuffer
{
 public:
  LazyStringCircularBuffer();
  int AddMessage(std::string strInput);
  std::string GetMessage();
};
#endif
