#include <stdexcept>
#include "DOMXMLParser.hpp"
#include <stdlib.h>
Framework::DOMXMLParser::DOMXMLParser()
{
// Trace::Log("Framework::DOMXMLParser::+DOMXMLParser()");
 
 try
 {
  XMLPlatformUtils::Initialize();
  m_pDOMParser = new DOMParser();
 }
 catch(const XMLException& toCatch)
 {
 // Trace::Log("Exception occurred during DOMParser memory allocation. Please check memory");
 }
 
// Trace::Log("Framework::DOMXMLParser::-DOMXMLParser()");
}

Framework::DOMXMLParser::~DOMXMLParser()
{
// Trace::Log("Framework::DOMXMLParser::~+DOMXMLParser()");
 
 delete m_pDOMParser;
 XMLPlatformUtils::Terminate();
 
 //Trace::Log("Framework::DOMXMLParser::~-DOMXMLParser()");
}

/**
 This will parse the XML file
*/
status Framework::DOMXMLParser::Parse(std::string filename)
{
 //Trace::Log("+Framework::DOMXMLParser::Parse(filename=)"+filename);
 
 m_strFilename = filename;
 m_pDOMParser->parse(filename.c_str());
 
 //Trace::Log("-Framework::DOMXMLParser::Parse()");
 return status::SUCCESS;
}

std::string Framework::DOMXMLParser::GetFilename()
{
 //Trace::Log("+Framework::DOMXMLParser::GetFilename()");
 
 //Trace::Log("-Framework::DOMXMLParser::GetFilename()");
 return m_strFilename;
}

std::string Framework::DOMXMLParser::GetValueAtTagName(std::string tagName, unsigned int index)
{
// Trace::Log("+Framework::DOMXMLParser::+GetValueAtTagName(std::string tagName, unsigned int index)");
 
 if(index > m_pDOMParser->getDocument().getElementsByTagName(DOMString::transcode(tagName.c_str())).getLength()-1)
 {
  throw std::range_error("index out of range!");
 }
 
 std::string value = std::string(m_pDOMParser->getDocument().getElementsByTagName(DOMString::transcode(tagName.c_str())).item(index).getFirstChild().getNodeValue().transcode());
 
 //Trace::Log("-Framework::DOMXMLParser::-GetValueAtTagName(std::string tagName, unsigned int index)");
 
 return value;
}

/**
 This will retrieve #text value of the node in the list starting from 1 index but does not mean the sequence is based on the XML entry
 Will exception when index out of range
*/
DOM_NodeList Framework::DOMXMLParser::GetList(std::string nodename)
{
 //Trace::Log("Framework::DOMXMLParser::+GetListAt(std::string strParentNodeName, unsigned int index)");
 
 DOM_Element element = m_pDOMParser->getDocument().getDocumentElement();
 
// Trace::Log("Framework::DOMXMLParser::-GetListAt(std::string strParentNodeName, unsigned int index)");
 
 return SeekNode(element,nodename);
}

DOM_NodeList Framework::DOMXMLParser::SeekNode(DOM_Node node, std::string nodeName)
{
 if(node!=0 && std::string(node.getNodeName().transcode())==nodeName) //verify if node is match
 {
  return node.getChildNodes();
 }
 else
 {
  if(node.hasChildNodes())
  { 
   return SeekNode(node.getFirstChild(),nodeName);
  }
  else
  {
   if(node!=0 && node.getNextSibling()!=0)
   {
    return SeekNode(node.getNextSibling(),nodeName);
   }
   else
   { 
    return SeekNode(node.getParentNode().getNextSibling(),nodeName);
   }
  }
 }
}

std::string Framework::DOMXMLParser::Get(std::string node, std::string id, std::string idval, std::string attrib)
{
 //Trace::Log("Framework::DOMXMLParser::+Get(std::string node, std::string id, std::string idval, std::string attrib)");
 
 DOM_Element element = m_pDOMParser->getDocument().getDocumentElement();
// Trace::Log("node="+node+",id="+id+",idval="+idval+",attrib="+attrib);
 std::string value = Iterate(element,node,id,idval,attrib);
 
 //Trace::Log("Framework::DOMXMLParser::-Get(std::string node, std::string id, std::string idval, std::string attrib)");
 
 return value;
}

/**
 This will iterate the whole XML document and search for the information you seek based on the arguments provided
 node - node where to start. cannot be empty
 strname - the node tag name to find. cannot be empty
 strid - the id of the node you want. empty if you want to retrieve the #text value
 stridval - the value of the id you want to look for. empty if you want to retrieve the value
 attrib - the attribute that you want to get the value. cannot be empty of stridval is not empty
*/
std::string Framework::DOMXMLParser::Iterate(DOM_Node node, std::string strname, std::string strid, std::string stridval, std::string attrib)
{
  if(node!=0 && std::string(node.getNodeName().transcode())==strname) //verify if node is match
  {//Trace::Log(std::string("node is a match = "+strname));
   if(strid!="" && node.hasAttributes()) //verify if this have attributes
   {//Trace::Log("node have attributes");
    DOM_NamedNodeMap map = node.getAttributes();
    for(unsigned int index=0; index<map.getLength(); index++)
    {
     //verify if strid match and stridval matc and attrib is empty get the #text value
     if(std::string(map.item(index).getNodeName().transcode())==strid && std::string(map.item(index).getNodeValue().transcode())==stridval && attrib=="") 
     {//Trace::Log("found match for id and its value but attrib is empty");
      return std::string(node.getFirstChild().getNodeValue().transcode());
     }
     else if(std::string(map.item(index).getNodeName().transcode())==strid && std::string(map.item(index).getNodeValue().transcode())==stridval && attrib!="")
     {//Trace::Log("found match for id and its value but attrib is NOT empty");
       //assume the attrib is not empty else wrong arguments passed in the function
       for(unsigned int index=0; index<map.getLength(); index++)
       {
        if(std::string(map.item(index).getNodeName().transcode())==attrib)
        {//Trace::Log("found match for id and its value and attrib");
         return std::string(map.item(index).getNodeValue().transcode());
        }
       }
     }
    }
    //for loop exited and have not found a match in the attributes
    //if idval is not found go to next sibling or go back to parent
    if(node!=0 && node.hasChildNodes()) //verify if element has childnodes and iterate
    {//Trace::Log("node have child nodes so iterate..");
     return Iterate(node.getFirstChild(), strname, strid, stridval, attrib);
    }
    else
    { if(node!=0 && node.getNextSibling()!=0)
     {//Trace::Log("node have NO child nodes so iterate next sibling..");
	return Iterate(node.getNextSibling(),strname,strid, stridval, attrib);
     }
     else
     { //Trace::Log("node is last and have no sibling so go back to parent and get parent next sibling");
       return Iterate(node.getParentNode().getNextSibling(),strname,strid, stridval, attrib);
     }
    }
   }
   else
   {//Trace::Log("node have NO attributes");
    return std::string(node.getFirstChild().getNodeValue().transcode());
   }
  }
  else
  {
   if(node!=0 && node.hasChildNodes()) //verify if element has childnodes and iterate
   {//Trace::Log("node have child nodes so iterate..");
    return Iterate(node.getFirstChild(), strname, strid, stridval, attrib);
   }
   else
   { if(node!=0 && node.getNextSibling()!=0)
     {//Trace::Log("node have NO child nodes so iterate next sibling..");
	return Iterate(node.getNextSibling(),strname,strid, stridval, attrib);
     }
     else
     { //Trace::Log("node is last and have no sibling so go back to parent and get parent next sibling");
       return Iterate(node.getParentNode().getNextSibling(),strname,strid, stridval, attrib);
     }
   }
  }
  
  return ""; //should not reach here
}

