//#include "Trace.hpp"
#include "Consts.hpp"
#include "GraphicalControl.hpp"

Framework::GraphicalControl::GraphicalControl()
{
// Trace::Log("Framework::GraphicalControl::+GraphicalControl()");
 
// Trace::Log("Framework::GraphicalControl::-GraphicalControl()");
}

Framework::GraphicalControl::~GraphicalControl()
{
// Trace::Log("Framework::GraphicalControl::+~GraphicalControl()");
 
 
// Trace::Log("Framework::GraphicalControl::-~GraphicalControl()");
}

unsigned long long Framework::GraphicalControl::GetAddress()
{
 return (unsigned long long)this;
}


