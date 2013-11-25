/* 
 * File:   CrashPadUtils.h
 * Author: Greg
 *
 * Created on October 7, 2013, 7:33 PM
 */

#ifndef CRASHPADUTILS_H
#define	CRASHPADUTILS_H


enum COMPONENT_TYPE { 
    PAD_TYPE = 0,          
    STRUT_TYPE,
    ENGINE_THRUST_TYPE,           
    PORT_THRUST_TYPE,
    STARBOARD_THRUST_TYPE, 
    FUEL_TANK_TYPE,
    CARGO_HOLD_TYPE
};

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
    
    bool operator==(DirectionVector& dv) const {
        return( x == dv.x && y == dv.y && z == dv.z);
    }
} ;
    

#endif	/* CRASHPADUTILS_H */

