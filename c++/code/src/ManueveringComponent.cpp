/* 
 * File:   ManueveringComponent.cpp
 * Author: Greg
 * 
 * Created on October 9, 2013, 6:58 PM
 */

#include "ManueveringComponent.h"

namespace Model
{
    ManueveringComponent::ManueveringComponent() : m_max_thrust(0.0), m_percent_thrust(0.0) {
        m_nozzel_direction.x = 0.0;
        m_nozzel_direction.y = 0.0;
        m_nozzel_direction.z = 0.0;        
    }

    ManueveringComponent::ManueveringComponent(const ManueveringComponent& orig) {
        m_thrust_curve     = orig.m_thrust_curve;
        m_max_thrust       = orig.m_max_thrust;
        m_percent_thrust   = orig.m_percent_thrust;
        m_nozzel_direction = orig.m_nozzel_direction;
    }

    ManueveringComponent::~ManueveringComponent() { }
    
    ManueveringComponent & ManueveringComponent::operator =(const ManueveringComponent& comp) {
        m_thrust_curve     = comp.m_thrust_curve;
        m_max_thrust       = comp.m_max_thrust;
        m_percent_thrust   = comp.m_percent_thrust;
        m_nozzel_direction = comp.m_nozzel_direction;
        
        return *this;
    }
    
    bool ManueveringComponent::set_max_thrust(double thrust) {
        bool retval = false;
        
        if(static_cast<int>(thrust) >= 0) {
            retval = true;
            m_max_thrust = thrust; 
       }
    }

}

