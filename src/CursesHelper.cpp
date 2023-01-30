#include <ncurses/ncurses.h>
#include "CursesHelper.hpp"
//#include "Trace.hpp"

void Framework::CursesHelper::PrintStringWithHighlight(std::string dispString)
{
 int mIndex;
 // check if string has the force no highlight sequence
 if (dispString.find("!@#") == 0)
 {//Trace::Log("found !@#");
  printw("%s", dispString.substr(3).c_str());
 } // Check if string needs to be highlighted
 else if( (mIndex=dispString.find("*")) != dispString.rfind("*")) 
 {//Trace::Log("found * ");
  // Yes, then extract the string to be hightlighted and highlight it
  std::string lStr, mStr, rStr, tmpBuff;
  lStr = dispString.substr(0,mIndex);
  tmpBuff = dispString.substr(mIndex + 1);
  mIndex = tmpBuff.rfind("*");
  mStr = tmpBuff.substr(0, mIndex);
  rStr = tmpBuff.substr(mIndex + 1);
  printw("%s", lStr.c_str());
  attron(COLOR_PAIR(6) | A_BOLD);
  printw("%s",mStr.c_str());
  attroff(COLOR_PAIR(6) | A_BOLD);
  attron(COLOR_PAIR(1));
  printw("%s",rStr.c_str());
 } 
 else 
 {//Trace::Log("print with no highlight");
  // Nope, then print the string with no highlight
  printw("%s", dispString.c_str());
 }
}
