#ifndef _DOMXMLPARSER_TEST_
#define _DOMXMLPARSER_TEST_

class DOMXMLParserTest : public CppUnit::TestCase
{
  CPPUNIT_TEST_SUITE(DOMXMLParserTest);
  CPPUNIT_TEST(ParseTest);
  CPPUNIT_TEST(GetFilenameTest);
  CPPUNIT_TEST(GetTest);
  CPPUNIT_TEST(GetListTest);
  CPPUNIT_TEST(GetValueAtTagNameTest);
  CPPUNIT_TEST_SUITE_END();
public:
 DOMXMLParserTest();
~DOMXMLParserTest();
 void ParseTest();
 void GetFilenameTest();
 void GetTest();
 void GetListTest();
 void GetValueAtTagNameTest();
};
#endif
