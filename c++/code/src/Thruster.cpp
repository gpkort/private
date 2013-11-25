/* 
 * File:   Thruster.cpp
 * Author: Greg
 * 
 * Created on October 12, 2013, 7:21 PM
 */

#include "Thruster.h"
namespace Model
{
Thruster::Thruster() 
        : ManueveringComponent()
{ 
    m_engine_type    = MANEUVER;
    m_percent_thrust = 0.0;  
}

Thruster::Thruster(unsigned int id) 
        : ManueveringComponent(id) 
{
     m_engine_type    = MANEUVER;
     m_percent_thrust = 0.0;  
}

Thruster::Thruster(const Thruster& orig) {
   m_object_name           = orig.m_object_name;
   m_object_id             = orig.m_object_id;
   m_object_mass           = orig.m_object_mass;
   m_cost                  = orig.m_cost;           
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
    
   ShipComponent::operator =(static_cast<ShipComponent const&>(thruster));
    
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

bool Thruster::operator ==(Thruster& rhs) const {
    return (
        m_object_name           == rhs.m_object_name           &&
        m_object_id             == rhs.m_object_id             &&
        m_object_mass           == rhs.m_object_mass           &&
        m_cost                  == rhs.m_cost                  &&           
        m_nozzel_direction      == rhs.m_nozzel_direction      &&
        m_engine_type           == rhs.m_engine_type           &&
        m_percent_thrust        == rhs.m_percent_thrust        &&
        m_fuel_curve            == rhs.m_fuel_curve            &&
        m_thrust_curve          == rhs.m_thrust_curve          && 
        m_has_calculated_fuel   == rhs.m_has_calculated_fuel   &&
        m_has_calculated_thrust == rhs.m_has_calculated_thrust &&
        m_fuel_slope            == rhs.m_fuel_slope            &&
        m_fuel_intercept        == rhs.m_fuel_intercept
    );
}

Thruster::~Thruster() {}
}

