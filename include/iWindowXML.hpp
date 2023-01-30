#ifndef _IWINDOW_XML_HPP_
#define _IWINDOW_XML_HPP_

#include <string>

namespace Framework
{
class iWindowXML
{
 public:
 /**
  Get the WINDOW element attributes rows and columns
  name    - name of the element
  sizerow - row size 
 */
 virtual unsigned int GetWindowRow()=0;
 virtual unsigned int GetWindowCol()=0;
 virtual std::string GetHeaderText()=0;
 virtual std::string GetOpModeText()=0;
 virtual std::string GetModelsText()=0;
 virtual std::string GetMainMenuText()=0;
};
};

#endif
