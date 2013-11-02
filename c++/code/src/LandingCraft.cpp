/* 
 * File:   LandingCraft.cpp
 * Author: Jack
 * 
 * Created on October 10, 2013, 3:08 PM
 */

#include "LandingCraft.h"

namespace Model {
LandingCraft::LandingCraft() :
        m_pads(),
        m_struts(),
        m_fuel_tank(),
        m_cargo_hold()
{}

LandingCraft::LandingCraft(const LandingCraft& orig) :
        m_pads(orig.m_pads),
        m_struts(orig.m_struts),
        m_fuel_tank(orig.m_fuel_tank),
        m_cargo_hold(orig.m_cargo_hold)
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


}

