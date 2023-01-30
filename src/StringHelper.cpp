#include "StringHelper.hpp"

std::string Framework::StringHelper::Tokenizer(std::string& orgString, std::string sDelimiter)
{
 std::string sResult;
 int mIndex;
 if((mIndex = orgString.find(sDelimiter.c_str())) != -1 ) 
 {
   sResult = orgString.substr(0, mIndex);
   orgString = orgString.substr(mIndex + 1);
 } 
 else 
 {
   sResult = orgString;
   orgString.clear();
 }
 
 return sResult;
}
