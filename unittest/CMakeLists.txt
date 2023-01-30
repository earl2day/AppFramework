cmake_minimum_required(VERSION 3.5)
project(FrameworkTests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(TEST_DIR /builds/active/src/rpscomm/ExternalLibs/Framework/unittest)
set(INC_DIR /builds/active/src/rpscomm/ExternalLibs/Framework/include)
set(SRC_DIR /builds/active/src/rpscomm/ExternalLibs/Framework/src)
set(IFACE_DIR ${INC_DIR}/interfaces)

set(XERCES_INC /builds/active/src/rpscomm/ExternalLibs/Xerces-C/1.7.0/include)
set(XERCES_SRC /builds/active/src/rpscomm/ExternalLibs/Xerces-C/1.7.0/src)

set(BOOST_DIR ${INC_DIR}/boost)

include_directories(
        ${XERCES_INC}
        ${XERCES_SRC}
        ${INC_DIR}
        ${SRC_DIR}
        ${IFACE_DIR}
)

add_executable(FrameworkTests
	/builds/active/src/rpscomm/ExternalLibs/Framework/unittest/main.cpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/unittest/DOMXMLParserTest.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/unittest/DOMXMLParserTest.cpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/Consts.hpp     
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/Object.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/iProjectXML.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/Model.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/src/Model.cpp
	/builds/active/src/rpscomm/ExternalLibs/Framework/include/XMLModel.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/src/XMLModel.cpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/DOMXMLParser.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/src/DOMXMLParser.cpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/Trace.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/src/Trace.cpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/LazyCircularBuffer.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/src/LazyCircularBuffer.cpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/ConsoleControl.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/src/ConsoleControl.cpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/View.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/src/View.cpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/ConsoleView.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/src/ConsoleView.cpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/Control.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/Conversion.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/src/Conversion.cpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/GraphicalControl.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/src/GraphicalControl.cpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/GraphicalView.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/src/GraphicalView.cpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/GraphicalView.hpp
        /builds/active/src/rpscomm/ExternalLibs/Framework/include/Object.hpp
        )

target_link_libraries(FrameworkTests
	cppunit
        pthread
        xerces-c1_7_0
        )
