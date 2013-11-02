/* 
 * File:   LandingCraft.h
 * Author: Jack
 *
 * Created on October 10, 2013, 3:08 PM
 */

#ifndef LANDINGCRAFT_H
#define	LANDINGCRAFT_H

#include <cstdlib>
#include <vector>
#include <map>
#include "Pad.h"
#include "CargoHold.h"
#include "FuelTank.h"
#include "Strut.h"

namespace Model
{

class LandingCraft : public GameObject {
public:
    static const int MAX_NUM_OF_LANDING_GEAR = 4;
    
public:
    LandingCraft();
    LandingCraft(const LandingCraft& orig);
    virtual ~LandingCraft();
    LandingCraft & operator =(const LandingCraft& landingCraft);
    
    inline void set_object_mass(const double objectMass){};
    
    inline std::vector<Pad>& get_pads() { return m_pads; };
    inline std::vector<Strut>& get_struts() { return m_struts; }
    inline FuelTank& get_fuel_tank() { return m_fuel_tank; }
    inline CargoHold& get_cargo_hold() {return m_cargo_hold; }
    
    void init_craft();
    
    
    
protected:
    
    
private:
    std::vector<Pad>   m_pads;
    std::vector<Strut> m_struts;
    FuelTank           m_fuel_tank;
    CargoHold          m_cargo_hold;
    
};
}

#endif	/* LANDINGCRAFT_H */

