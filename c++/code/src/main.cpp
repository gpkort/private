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


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Model::DurableComponent dc, dc1;
    
    dc.set_object_name("Blah");
    dc1 = dc;
    cout << "Hey : " << dc1.get_object_name() << endl;
    
    map<float, float> test_map;
    test_map[2.0f] = 4.0f;
    test_map[1.0f] = 2.0f;
    test_map[4.0f] = 8.0f;
    test_map[3.0f] = 6.0f;
    
    map<float, float>::iterator itr;
    for(itr = test_map.begin(); itr != test_map.end(); itr++) {
        cout << "x:" << itr->first << ", y:" << itr->second << endl;
    }
    
    return 0;
}

