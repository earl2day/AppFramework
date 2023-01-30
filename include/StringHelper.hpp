#ifndef _STRING_HELPER_HPP_
#define _STRING_HELPER_HPP_

#include <string>

namespace Framework
{
class StringHelper
{
 public:
 static std::string Tokenizer(std::string& orgString, std::string sDelimiter);
};
};
#endif
