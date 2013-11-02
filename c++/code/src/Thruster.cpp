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
   m_engine_type    = ENGINE_TYPE::MANEUVER;
   m_max_thrust     = 0.0;
   m_percent_thrust = 0.0;
}

Thruster::Thruster(const Thruster& orig) {
   m_nozzel_direction = orig.m_nozzel_direction;
   m_engine_type      = orig.m_engine_type;
   m_max_thrust       = orig.m_max_thrust;
   m_percent_thrust   = orig.m_percent_thrust;
}

Thruster & Thruster::operator =(const Thruster& thruster) {
   m_nozzel_direction = thruster.m_nozzel_direction;
   m_engine_type      = thruster.m_engine_type;
   m_max_thrust       = thruster.m_max_thrust;
   m_percent_thrust   = thruster.m_percent_thrust;
   
   return *this;
}

Thruster::~Thruster() {
}
}

