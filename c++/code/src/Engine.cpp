/* 
 * File:   Engine.cpp
 * Author: Jack
 * 
 * Created on October 11, 2013, 3:54 PM
 */

#include "Engine.h"

namespace Model
{
Engine::Engine() { m_engine_type = LANDING;}

Engine::~Engine() {}

Engine & Engine::operator =(const Engine& engine) {
   m_nozzel_direction = engine.m_nozzel_direction;
   m_engine_type      = engine.m_engine_type;
   m_max_thrust       = engine.m_max_thrust;
   m_percent_thrust   = engine.m_percent_thrust;
   
   return *this;
}

Engine::Engine(const Engine& orig) {
   m_nozzel_direction = orig.m_nozzel_direction;
   m_engine_type      = orig.m_engine_type;
   m_max_thrust       = orig.m_max_thrust;
   m_percent_thrust   = orig.m_percent_thrust;
}


}

