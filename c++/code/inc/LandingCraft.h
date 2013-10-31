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
#include "Pad.h"
#include "CargoHold.h"
#include "FuelTank.h"
#include "Strut.h"

namespace Model
{

class LandingCraft {
public:
    LandingCraft();
    LandingCraft(const LandingCraft& orig);
    virtual ~LandingCraft();
    LandingCraft & operator =(const LandingCraft& landingCraft);
private:
    std::vector<Pad>   m_pads;
    std::vector<Strut> m_struts;
    FuelTank           m_fuel_tank;
    CargoHold          m_cargo_hold;
    
};
}

#endif	/* LANDINGCRAFT_H */

