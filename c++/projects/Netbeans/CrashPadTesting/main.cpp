/* 
 * File:   main.cpp
 * Author: Jack
 *
 * Created on November 3, 2013, 1:05 PM
 */

#include <cstdlib>
#include "gmock/gmock.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
   cout << "Hello" << endl; 
   testing::InitGoogleMock(&argc, argv);
   return RUN_ALL_TESTS(); 
}

