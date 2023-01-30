/**
 Thin layer that provides higher level abstraction than Apache DOM
 but not specific to any application
*/

#ifndef _DOM_XML_PARSER_HPP_
#define _DOM_XML_PARSER_HPP_

#include <string>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/DOMParser.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#include "Consts.hpp"
#include "XMLParser.hpp"


namespace Framework
{
class DOMXMLParser : public XMLParser
{
 public:
  DOMXMLParser();
  ~DOMXMLParser();
  std::string GetFilename();
  std::string Iterate(DOM_Node node, std::string strname, std::string strid, std::string stridval, std::string attrib);
  status Parse(std::string filename);
  std::string Get(std::string node, std::string id, std::string idval, std::string attrib);
  std::string GetValueAtTagName(std::string tagName, unsigned int index);
  
  DOM_NodeList GetList(std::string nodename);
  DOM_NodeList SeekNode(DOM_Node node, std::string nodename);

 private:
  DOMParser* m_pDOMParser;
  
};
};
#endif
