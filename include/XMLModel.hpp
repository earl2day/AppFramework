#ifndef _FRAMEWORK_XML_MODEL_HPP_
#define _FRAMEWORK_XML_MODEL_HPP_

#include <string>

#include "Model.hpp"
#include "XMLParser.hpp"

namespace Framework
{
class XMLModel : public Model
{
 public:
  XMLModel(std::string filename);
  ~XMLModel();
  bool IsFileExist(std::string path);
  std::string GetFilename();
  
 protected:
  Framework::XMLParser* m_pParser;
};
};
#endif
