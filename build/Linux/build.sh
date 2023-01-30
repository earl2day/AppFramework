#!/bin/bash
rm *.o framework.a
g++ -c ../../src/* -I../../include -I../../../Xerces-C/1.7.0/include
ar rcs framework.a *.o

