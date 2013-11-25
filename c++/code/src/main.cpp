/* 
 * File:   main.cpp
 * Author: Jack
 *
 * Created on October 6, 2013, 8:28 AM
 */

#include <cstdlib>
#include <iostream>
#include "DurableComponent.h"
#include <map>
#include "LandingCraft.h"


using namespace std;
using namespace Model;

/*
 * 
 */
int main(int argc, char** argv) {
    Model::DurableComponent dc, dc1;
   
    
    dc.set_object_name("Blah");
    dc1 = dc;
    cout << "Hey : " << dc1.get_object_name() << endl;
    
    LandingCraft lc(9.8);
    
    return 0;
}

