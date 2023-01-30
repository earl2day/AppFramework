#ifndef _IAPP_XML_HPP_
#define _IAPP_XML_HPP_

#include <string>

namespace Framework
{
class iAppXML
{
 public:
  virtual std::string GetExecutable()=0;
  virtual std::string GetVersion()=0;
  virtual std::string GetCopyRight()=0;
};
};

#endif
