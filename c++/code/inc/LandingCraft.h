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
#include "Thruster.h"

namespace Model
{

class LandingCraft : public GameObject {
public:
    static const int MAX_NUM_OF_LANDING_GEAR = 4;
    
public:
    LandingCraft(double gravityAcceleration);
    LandingCraft(const LandingCraft& orig);
    ~LandingCraft();
    LandingCraft & operator =(const LandingCraft& landingCraft);
    
    inline void set_object_mass(const double objectMass){};
    
    inline std::vector<Pad>& get_pads() { return m_pads; };
    inline std::vector<Strut>& get_struts() { return m_struts; }
    inline FuelTank& get_fuel_tank() { return m_fuel_tank; }
    inline CargoHold& get_cargo_hold() {return m_cargo_hold; }
    inline double get_gravity_acceleration() { return m_gravity_acceleration; }
    inline double get_altitude() { return m_altitude; }
    inline std::vector<Thruster> get_thrusters() { return m_thrusters; }
    
    void init_craft();
    double get_position(double percentOfThrust, double timedelta);   
    
    
protected:
    
    
private:
    std::vector<Pad>      m_pads;
    std::vector<Strut>    m_struts;
    std::vector<Thruster> m_thrusters;
    FuelTank              m_fuel_tank;
    CargoHold             m_cargo_hold;
    double                m_gravity_acceleration;
    double                m_altitude;
};
}

#endif	/* LANDINGCRAFT_H */

