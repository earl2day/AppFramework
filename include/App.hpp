#ifndef _APP_HPP_
#define _APP_HPP_

#include "Control.hpp"
#include "View.hpp"
#include "Model.hpp"

namespace Framework
{
class App
{
 public:
 	App();
 	void SetParam(int argc, char* argv[]);
 	virtual int Run()=0;
 protected:
 	int m_argc;
 	char** m_argv;
 	Framework::Control *m_control;
        Framework::View *m_view;
        Framework::Model *m_model;
};
};
#endif
