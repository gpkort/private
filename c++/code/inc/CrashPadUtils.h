/* 
 * File:   CrashPadUtils.h
 * Author: Jack
 *
 * Created on October 7, 2013, 7:33 PM
 */

#ifndef CRASHPADUTILS_H
#define	CRASHPADUTILS_H

enum FUEL_TYPE {UNDEFINED_FUEL = 0, LIQUID, SOLID, GAS};

enum ENGINE_TYPE {UNDEFINED_ENGINE = 0, MANEUVER, LANDING};

struct DirectionVector { 
    double x, y, z;
    
    DirectionVector() : x(0.0), y(0.0), z(0.0) {  }
    DirectionVector(const DirectionVector& orig) :
        x(orig.x), y(orig.y), z(orig.z)
    { }
    
    DirectionVector& operator=(const DirectionVector& dv) {
        x = dv.x;
        y = dv.y;
        z = dv.z;
        
        return *this;
    }
} ;
    

#endif	/* CRASHPADUTILS_H */

