#include <cppunit/extensions/HelperMacros.h>
#include "DOMXMLParserTest.hpp"
#include "../include/DOMXMLParser.hpp"
#include <stdexcept>

CPPUNIT_TEST_SUITE_REGISTRATION(DOMXMLParserTest);

DOMXMLParserTest::DOMXMLParserTest()
{
}

DOMXMLParserTest::~DOMXMLParserTest()
{
}

void DOMXMLParserTest::ParseTest()
{
  Framework::DOMXMLParser parser;
  CPPUNIT_ASSERT(status::SUCCESS == parser.Parse("../../xml/Project.xml"));
}

void DOMXMLParserTest::GetFilenameTest()
{
  Framework::DOMXMLParser parser;
  CPPUNIT_ASSERT(status::SUCCESS == parser.Parse("../../xml/Project.xml"));
  CPPUNIT_ASSERT(parser.GetFilename()=="../../xml/Project.xml");
}

void DOMXMLParserTest::GetTest()
{
 Framework::DOMXMLParser parser;
 parser.Parse("Window.xml");
 CPPUNIT_ASSERT(parser.Get("OPMODE","id","opmod","text")=="Operation Mode:");
 CPPUNIT_ASSERT(parser.Get("INPUT","","","")=="Enter Selection:");
 CPPUNIT_ASSERT(parser.Get("WINDOW","id","root","col")=="80");
 CPPUNIT_ASSERT(parser.Get("MAIN_MENU","id","main","text")=="Main Menu");
}

void DOMXMLParserTest::GetListTest()
{
 Framework::DOMXMLParser parser;
 parser.Parse("../../xml/Project.xml");
  
 CPPUNIT_ASSERT(parser.GetList("PROJECT").getLength()>0);
}

void DOMXMLParserTest::GetValueAtTagNameTest()
{
 Framework::DOMXMLParser parser;
 parser.Parse("../../xml/Project.xml");
 
 CPPUNIT_ASSERT(parser.GetValueAtTagName("ARTIFACT",0)=="App.xml");
}
