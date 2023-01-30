#include "Trace.hpp"
#include "View.hpp"

Framework::View::View()
{
 //Trace::Log("Framework::View::+View");
// Trace::Log("Framework::View::-View");
}

Framework::View::~View()
{
// Trace::Log("Framework::View::+~View");
// Trace::Log("Framework::View::-~View");
}

unsigned long long Framework::View::GetAddress()
{
// Trace::Log("Framework::View::+GetAddress");
// Trace::Log("Framework::View::-GetAddress");
 return (unsigned long long)this;
}
