#include <fstream>
#include "Trace.hpp"
#include "Consts.hpp"

#include "XMLModel.hpp"
#include "DOMXMLParser.hpp"

Framework::XMLModel::XMLModel(std::string filename)
{
 m_pParser = dynamic_cast<XMLParser*>(new DOMXMLParser());
 m_pParser->Parse(filename);
}

Framework::XMLModel::~XMLModel()
{
}

/**
 Verify if the file exist
*/
bool Framework::XMLModel::IsFileExist(std::string path="")
{
 //Trace::Log("Framework::XMLModel::+IsFileExist(std::string path="")");
 
 bool status=false;
 if(path=="")
 {
  //do not feed the argument to avoid segmentation fault
 }
 else
 {
  std::ifstream f(path.c_str());
  status=f.good();
  //Trace::Log(path+"="+(status?"true":"false"));
 }
 
 //Trace::Log("Framework::XMLModel::-IsFileExist(std::string path="")");
 
 return status;
}

std::string Framework::XMLModel::GetFilename()
{
 //Trace::Log("Framework::XMLModel::+GetFilename()");
 //Trace::Log("Framework::XMLModel::-GetFilename()");
 return m_pParser->GetFilename();
}



