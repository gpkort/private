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
    LandingCraft();
    LandingCraft(double gravityAcceleration);
    LandingCraft(double gravityAcceleration, double current_altitude);
    LandingCraft(const LandingCraft& orig);
    ~LandingCraft();
    LandingCraft & operator =(const LandingCraft& landingCraft);
    
    inline void set_object_mass(const double objectMass){};
    double get_object_mass();
    
    inline const std::vector<Pad>& get_pad_list() { return m_pads; };
    inline const std::vector<Strut>& get_strut_list() { return m_struts; }
    
    inline void clear_pad_list() { m_pads.clear(); }
    inline void clear_strut_list() { m_struts.clear(); }
    
    void add_pad(Pad pad);
    void remove_pad( int objectID);
    Pad& get_pad_by_index(unsigned int index);
    Pad& get_pad_by_id(int objectID);
    
    void add_strut(Strut strut);
    void remove_strut( int objectID);
    Strut& get_strut_by_index(unsigned int index);
    Strut& get_strut_by_id(int objectID);
    
    void set_fuel_tank(FuelTank fuelTank);
    void set_cargo_hold(CargoHold cargoHolder);
    void set_engine(Thruster engine);
    void set_port_thruster(Thruster portThruster);
    void set_starboard_thruster(Thruster starboardThruster);
    
    
    
    inline FuelTank& get_fuel_tank() { return m_fuel_tank; };
    inline CargoHold& get_cargo_hold() {return m_cargo_hold; };
    inline Thruster& get_engine() { return m_engine; };
    inline Thruster& get_port_thruster() { return m_port_thruster; };
    inline Thruster& get_starboard_thruster() { return m_starboard_thruster; };
    
    inline void set_gravity_acceleration(double acceleration) {m_gravity_acceleration = acceleration;};
    inline double get_gravity_acceleration() { return m_gravity_acceleration; }
    
    inline void set_altitude(double altitude) { m_altitude = altitude; }
    inline double get_altitude() { return m_altitude; }
    
    
    void engage_engine(double percentOfThrust, double timedelta);  

private:
    std::vector<Pad>      m_pads;
    std::vector<Strut>    m_struts;
    Thruster              m_engine;
    Thruster              m_port_thruster;
    Thruster              m_starboard_thruster;
    FuelTank              m_fuel_tank;
    CargoHold             m_cargo_hold;
    double                m_gravity_acceleration;
    double                m_altitude;
    
    std::map<unsigned int, COMPONENT_TYPE> m_id_map;
};
}

#endif	/* LANDINGCRAFT_H */

