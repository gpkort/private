/* 
 * File:   LandingCraft.cpp
 * Author: Jack
 * 
 * Created on October 10, 2013, 3:08 PM
 */

#include "LandingCraft.h"
#include <stdexcept>
#include <iostream>

using namespace std;
namespace Model {

LandingCraft::LandingCraft() :
        m_pads(),
        m_struts(),
        m_engine(),
        m_port_thruster(),
        m_starboard_thruster(),
        m_fuel_tank(),
        m_cargo_hold(),
        m_gravity_acceleration(0.0),
        m_altitude(0.0),
        m_id_map()
{}    

LandingCraft::LandingCraft(double gravityAcceleration) :
        m_pads(),
        m_struts(),
        m_engine(),
        m_port_thruster(),
        m_starboard_thruster(),
        m_fuel_tank(),
        m_cargo_hold(),
        m_gravity_acceleration(gravityAcceleration),
        m_altitude(0.0),
        m_id_map()
{}

LandingCraft::LandingCraft(double gravityAcceleration, double current_altitude) :
        m_pads(),
        m_struts(),
        m_engine(),
        m_port_thruster(),
        m_starboard_thruster(),
        m_fuel_tank(),
        m_cargo_hold(),
        m_gravity_acceleration(gravityAcceleration),
        m_altitude(current_altitude),
        m_id_map()
{ }

LandingCraft::LandingCraft(const LandingCraft& orig) :
        m_pads(orig.m_pads),
        m_struts(orig.m_struts),
        m_engine(orig.m_engine),
        m_port_thruster(orig.m_port_thruster),
        m_starboard_thruster(orig.m_starboard_thruster),
        m_fuel_tank(orig.m_fuel_tank),
        m_cargo_hold(orig.m_cargo_hold),
        m_gravity_acceleration(orig.m_gravity_acceleration),
        m_altitude(orig.m_altitude),
        m_id_map()
{
    LandingCraft::GameObject(static_cast<GameObject const&>(orig));
}

LandingCraft::~LandingCraft() {}

LandingCraft & LandingCraft::operator =(const LandingCraft& landingCraft) {
    if(this == &landingCraft) return *this;
    
    GameObject::operator =(static_cast<GameObject const&>(landingCraft));
    
    m_pads               = landingCraft.m_pads;
    m_struts             = landingCraft.m_struts;
    m_engine             = landingCraft.m_engine;
    m_port_thruster      = landingCraft.m_port_thruster;
    m_starboard_thruster = landingCraft.m_starboard_thruster;
    m_fuel_tank          = landingCraft.m_fuel_tank;
    m_cargo_hold         = landingCraft.m_cargo_hold;
    m_id_map             = landingCraft.m_id_map;
    
    return *this;
}

void LandingCraft::engage_engine(double percentOfThrust, double timedelta) {
    double upforce = m_engine.get_thrust(percentOfThrust); 
    double fuelmass0 = m_fuel_tank.get_current_percent() * 1;
    double fuelused = m_engine.get_burn_rate(percentOfThrust);
    double massoffuel = fuelused * m_fuel_tank.get_fuel_density();
    
     
}

double LandingCraft::get_object_mass() {
    vector<Pad>::iterator pitr;
    for(pitr = m_pads.begin(); pitr != m_pads.end(); ++pitr) {
        m_object_mass += pitr->get_object_mass();
    }
    
    vector<Strut>::iterator sitr;
    for(sitr = m_struts.begin(); sitr != m_struts.end(); ++sitr) {
        m_object_mass += sitr->get_object_mass();
    }
    
    m_object_mass += m_engine.get_object_mass();
    m_object_mass += m_port_thruster.get_object_mass();
    m_object_mass += m_starboard_thruster.get_object_mass();
    m_object_mass += m_cargo_hold.get_object_mass();
    m_object_mass += m_fuel_tank.get_object_mass();
    
    return m_object_mass;
    
}

void LandingCraft::add_pad(Pad pad) {
    map<unsigned int, COMPONENT_TYPE>::iterator mitr =
        m_id_map.find(pad.get_object_id());
    
    if(mitr != m_id_map.end())
        throw runtime_error("Pad with this object id already exists");
        
   m_pads.push_back(pad);
   m_id_map.insert(pair<unsigned int, COMPONENT_TYPE>(pad.get_object_id(), PAD_TYPE));   
}

void LandingCraft::remove_pad( int objectID) {
     map<unsigned int, COMPONENT_TYPE>::iterator mitr = m_id_map.find(objectID);
    
    if(mitr == m_id_map.end())
        throw runtime_error("Pad with this object id does not exists");
    
     m_id_map.erase(mitr);
    
    vector<Pad>::iterator itr;

    for(itr = m_pads.begin(); itr != m_pads.end(); ++itr) {
        if(objectID == itr->get_object_id()) {
            m_pads.erase(itr);
            return;
        }
    }    
    throw runtime_error("No Pad exists");
}

Pad& LandingCraft::get_pad_by_index(unsigned int index) {
    if(index < m_pads.size() - 1)
        return (m_pads.at(index));
    else 
        throw runtime_error("Pad index out of range!");
}

Pad& LandingCraft::get_pad_by_id(int objectID) {
    vector<Pad>::iterator itr;

    for(itr = m_pads.begin(); itr != m_pads.end(); ++itr) {
        if(objectID == itr->get_object_id()) {
            return static_cast<Pad&>(*itr);
        }
    }    
    throw runtime_error("No Pad exists");
}

void LandingCraft::add_strut(Strut strut) {
    map<unsigned int, COMPONENT_TYPE>::iterator mitr =
        m_id_map.find(strut.get_object_id());
    
    if(mitr != m_id_map.end())
        throw runtime_error("Pad with this object id already exists");
        
   m_struts.push_back(strut);
   m_id_map.insert(pair<unsigned int, COMPONENT_TYPE>(strut.get_object_id(), STRUT_TYPE));    
}

void LandingCraft::remove_strut( int objectID) {
     map<unsigned int, COMPONENT_TYPE>::iterator mitr = m_id_map.find(objectID);
    
    if(mitr == m_id_map.end())
        throw runtime_error("Strut with this object id does not exists");
    
    m_id_map.erase(mitr);
     
    vector<Strut>::iterator itr;

    for(itr = m_struts.begin(); itr != m_struts.end(); ++itr) {
        if(objectID == itr->get_object_id()) {
            m_struts.erase(itr);
            return;
        }
    }    
    throw runtime_error("No Strut exists");
}

Strut& LandingCraft::get_strut_by_index(unsigned int index) {
    if(index < m_struts.size() - 1)
        return (m_struts.at(index));
    else 
        throw runtime_error("Strut index out of range!");
}

Strut& LandingCraft::get_strut_by_id(int objectID) {
    vector<Strut>::iterator itr;

    for(itr = m_struts.begin(); itr != m_struts.end(); ++itr) {
        if(objectID == itr->get_object_id()) {
            return static_cast<Strut&>(*itr);
        }
    }    
    throw runtime_error("No Strut exists");
}

void LandingCraft::set_fuel_tank(FuelTank fuelTank) {
    map<unsigned int, COMPONENT_TYPE>::iterator mitr =
        m_id_map.find(fuelTank.get_object_id());
    
    if(mitr != m_id_map.end()) {
        if(mitr->second == FUEL_TANK_TYPE)
            m_id_map.erase(mitr);
        else
            throw runtime_error("Component with that id exists");
    }
    
    m_id_map.insert(pair<unsigned int, COMPONENT_TYPE>(
                fuelTank.get_object_id(), FUEL_TANK_TYPE)
    );
    m_fuel_tank = fuelTank;    
}

void LandingCraft::set_cargo_hold(CargoHold cargoHolder) {
     map<unsigned int, COMPONENT_TYPE>::iterator mitr =
        m_id_map.find(cargoHolder.get_object_id());
    
    if(mitr != m_id_map.end()) {
        if(mitr->second == CARGO_HOLD_TYPE)
            m_id_map.erase(mitr);
        else
            throw runtime_error("Component with that id exists");
    }
    
    m_id_map.insert(pair<unsigned int, COMPONENT_TYPE>(
                cargoHolder.get_object_id(), CARGO_HOLD_TYPE)
    );
    m_cargo_hold = cargoHolder;  
}

void LandingCraft::set_engine(Thruster engine) {
    map<unsigned int, COMPONENT_TYPE>::iterator mitr =
        m_id_map.find(engine.get_object_id());
    
    if(mitr != m_id_map.end()) {
        if(mitr->second == ENGINE_THRUST_TYPE)
            m_id_map.erase(mitr);
        else
            throw runtime_error("Component with that id exists");
    }
    
    m_id_map.insert(pair<unsigned int, COMPONENT_TYPE>(engine.get_object_id(), 
            ENGINE_THRUST_TYPE));
   m_engine = engine;   
}

void LandingCraft::set_port_thruster(Thruster portThruster) {
    map<unsigned int, COMPONENT_TYPE>::iterator mitr =
        m_id_map.find(portThruster.get_object_id());
    
    if(mitr != m_id_map.end()) {
        if(mitr->second == PORT_THRUST_TYPE)
            m_id_map.erase(mitr);
        else
            throw runtime_error("Component with that id exists");
    }
    
    m_id_map.insert(pair<unsigned int, COMPONENT_TYPE>(portThruster.get_object_id(), 
            PORT_THRUST_TYPE));
   m_port_thruster = portThruster;
} 

void LandingCraft::set_starboard_thruster(Thruster starboardThruster) {
    map<unsigned int, COMPONENT_TYPE>::iterator mitr =
        m_id_map.find(starboardThruster.get_object_id());
    
    if(mitr != m_id_map.end()) {
        if(mitr->second == PORT_THRUST_TYPE)
            m_id_map.erase(mitr);
        else
            throw runtime_error("Component with that id exists");
    }
    
    m_id_map.insert(pair<unsigned int, COMPONENT_TYPE>(starboardThruster.get_object_id(), 
            STARBOARD_THRUST_TYPE));
    m_starboard_thruster = starboardThruster;
}


}

