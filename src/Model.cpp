#include "Model.hpp"

unsigned long long Framework::Model::GetAddress()
{
 return reinterpret_cast<unsigned long long>(this);
}
