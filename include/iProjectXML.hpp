#ifndef _I_PROJECT_XML_HPP_
#define _I_PROJECT_XML_HPP_

#include <string>

namespace Framework
{
class iProjectXML
{
 public:
  /**
   Verify if all the files in Project.xml exist
  */
  virtual status CheckAllFiles()=0;
  /**
   Retrieves the artifact content using index
  */
  virtual std::string GetArtifact(unsigned int index)=0;
  /**
   Retrieves the full path of the location of the artifacts
  */
  virtual std::string GetRootFullPath()=0;
  /**
   Retrieves the path of the artifact
  */
  virtual std::string GetArtifactPath(std::string filename)=0;
};
};

#endif
