/* 
 * File:   LandingCraft.cpp
 * Author: Jack
 * 
 * Created on October 10, 2013, 3:08 PM
 */

#include "LandingCraft.h"

using namespace std;
namespace Model {
LandingCraft::LandingCraft(double gravityAcceleration) :
        m_pads(),
        m_struts(),
        m_fuel_tank(),
        m_cargo_hold(),
        m_gravity_acceleration(gravityAcceleration),
        m_altitude(0.0)
{}

LandingCraft::LandingCraft(const LandingCraft& orig) :
        m_pads(orig.m_pads),
        m_struts(orig.m_struts),
        m_fuel_tank(orig.m_fuel_tank),
        m_cargo_hold(orig.m_cargo_hold),
        m_gravity_acceleration(orig.m_gravity_acceleration),
        m_altitude(orig.m_altitude)
{
    LandingCraft::GameObject(static_cast<GameObject const&>(orig));
}

LandingCraft::~LandingCraft() {}

LandingCraft & LandingCraft::operator =(const LandingCraft& landingCraft) {
    GameObject::operator =(static_cast<GameObject const&>(landingCraft));
    
    m_pads       = landingCraft.m_pads;
    m_struts     = landingCraft.m_struts;
    m_fuel_tank  = landingCraft.m_fuel_tank;
    m_cargo_hold = landingCraft.m_cargo_hold;
    
    return *this;
}

void LandingCraft::init_craft() {
    vector<Pad>::iterator pitr;
    for(pitr = m_pads.begin(); pitr != m_pads.end(); ++pitr) {
        m_object_mass += pitr->get_object_mass();
    }
    
    vector<Strut>::iterator sitr;
    for(sitr = m_struts.begin(); sitr != m_struts.end(); ++sitr) {
        m_object_mass += sitr->get_object_mass();
    }
}


}

