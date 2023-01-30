//#include "Trace.hpp"
#include "App.hpp"

Framework::App::App()
{
 m_control=0;
 m_view=0;
 m_model=0;
}

void Framework::App::SetParam(int argc, char* argv[])
{
 m_argc=argc;
 m_argv=argv;
}

extern Framework::App* g_appInstance;

int main(int argc, char* argv[])
{
 //Trace::Log("::+main");
 
 g_appInstance->SetParam(argc,argv);
 int exit = g_appInstance->Run();
 
 //Trace::Log("::-main");
 return exit;
}

