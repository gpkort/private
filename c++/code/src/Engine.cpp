/* 
 * File:   Engine.cpp
 * Author: Jack
 * 
 * Created on October 11, 2013, 3:54 PM
 */

#include "Engine.h"

namespace Model
{
Engine::Engine() : ManueveringComponent(){}

Engine::~Engine() {}

Engine & Engine::operator =(const Engine& engine) {
   if(this == &engine) return *this;
       
   m_nozzel_direction      = engine.m_nozzel_direction;
   m_engine_type           = engine.m_engine_type;
   m_percent_thrust        = engine.m_percent_thrust;
   m_fuel_curve            = engine.m_fuel_curve;
   m_thrust_curve          = engine.m_thrust_curve; 
   m_has_calculated_fuel   = engine.m_has_calculated_fuel;
   m_has_calculated_thrust = engine.m_has_calculated_thrust;
   m_fuel_slope            = engine.m_fuel_slope;
   m_fuel_intercept        = engine.m_fuel_intercept;
   m_thrust_slope          = engine.m_thrust_slope;
   m_thrust_intercept      = engine.m_thrust_intercept;
   
   return *this;
}

Engine::Engine(const Engine& orig) {
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


}

