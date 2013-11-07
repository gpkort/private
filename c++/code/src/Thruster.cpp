/* 
 * File:   Thruster.cpp
 * Author: Jack
 * 
 * Created on October 12, 2013, 7:21 PM
 */

#include "Thruster.h"
namespace Model
{
Thruster::Thruster() {
   m_engine_type    = MANEUVER;
   m_percent_thrust = 0.0;
}

Thruster::Thruster(const Thruster& orig) {
   m_nozzel_direction      = orig.m_nozzel_direction;
   m_engine_type           = orig.m_engine_type;
   m_percent_thrust        = orig.m_percent_thrust;
   m_fuel_curve            = orig.m_fuel_curve;
   m_thrust_curve          = orig.m_thrust_curve; 
   m_has_calculated_fuel   = orig.m_has_calculated_fuel;
   m_has_calculated_thrust = orig.m_has_calculated_thrust;
   m_fuel_slope            = orig.m_fuel_slope;
   m_fuel_intercept        = orig.m_fuel_intercept;
}

Thruster & Thruster::operator =(const Thruster& thruster) {
    if(this == &thruster) return *this;
    
   m_nozzel_direction      = thruster.m_nozzel_direction;
   m_engine_type           = thruster.m_engine_type;
   m_percent_thrust        = thruster.m_percent_thrust;
   m_fuel_curve            = thruster.m_fuel_curve;
   m_thrust_curve          = thruster.m_thrust_curve; 
   m_has_calculated_fuel   = thruster.m_has_calculated_fuel;
   m_has_calculated_thrust = thruster.m_has_calculated_thrust;
   m_fuel_slope            = thruster.m_fuel_slope;
   m_fuel_intercept        = thruster.m_fuel_intercept;
   
   return *this;
}

Thruster::~Thruster() {}
}

