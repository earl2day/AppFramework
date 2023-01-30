#include <iostream>
#include "LazyStringCircularBuffer.hpp"

#define SIZE 100
static int m_nPointer=0;
static int m_nIndex=0;
static std::string m_strArray[SIZE];

int LazyStringCircularBuffer::AddMessage(std::string strInput)
{//need to add synchronization object here if ever this function is called in other threads
 if(m_nPointer<SIZE)
 {
  m_strArray[m_nPointer]=strInput+"\n";
  m_nPointer++;
 }
 else
 {
  m_nPointer=0;
  m_strArray[m_nPointer]=strInput+"\n";
  m_nPointer++;
 }
 
 return 0;
}

std::string LazyStringCircularBuffer::GetMessage()
{
 std::string message = m_strArray[m_nIndex];
 if(message!="")
 {
  m_strArray[m_nIndex]="";
  if(m_nIndex<SIZE) m_nIndex++;
  else m_nIndex=0;
 }
 else
 {
  //do nothing since we don't have message to process
 }
 
 return message;
}
