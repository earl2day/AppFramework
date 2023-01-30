#ifndef _XMLPARSER_HPP_
#define _XMLPARSER_HPP_

#include <string>
#include <xercesc/dom/DOM.hpp>

#include "Consts.hpp"

namespace Framework
{
class XMLParser
{
 public:
  virtual status Parse(std::string filename)=0;
  virtual std::string GetFilename()=0;
  virtual std::string Get(std::string node, std::string id, std::string idval, std::string attrib)=0;
  virtual DOM_NodeList GetList(std::string nodename)=0;
  virtual std::string GetValueAtTagName(std::string tagName, unsigned int index)=0;
  
 protected:
  std::string m_strFilename;
};
};
#endif
