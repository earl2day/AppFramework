#include <pthread.h>
#include <fstream>
#include <string>
#include "Trace.hpp"
#include "LazyStringCircularBuffer.hpp"

static LazyStringCircularBuffer g_CircularBuff;
static pthread_t g_thread;
extern std::string g_traceFilename;

void* LogMessage(void *ptr);

Trace::Trace()
{
 pthread_create(&g_thread,NULL,LogMessage,(void*)&g_CircularBuff);
}

void Trace::Start(std::string className, std::string methodName)
{
 //add start time, class name and method name
 g_CircularBuff.AddMessage("+"+className+"::"+"+"+methodName);
}

void Trace::Log(std::string message)
{
 //add start time, class name and method name
 g_CircularBuff.AddMessage(message);
}

void Trace::Stop(std::string className, std::string methodName, std::string retVal)
{
 //add stop time, class name and method name, return value
 g_CircularBuff.AddMessage("+"+className+"::"+"-"+methodName+"="+retVal);
}

void* LogMessage(void *ptr)
{
 std::ofstream myfile;
 myfile.open (g_traceFilename);
 std::string message="";
 do
 {
  message = ((LazyStringCircularBuffer*)ptr)->GetMessage();
  myfile << message;
 }
 while(message!="");
 
 myfile.close();
}

