/* 
 * File:   CargoHold.cpp
 * Author: Jack
 * 
 * Created on October 11, 2013, 9:37 AM
 */

#include "CargoHold.h"

namespace Model {
CargoHold::CargoHold() : DurableComponent(),
        m_max_mass(0.0), m_current_mass(0.0), m_volume(0.0) 
{}

CargoHold::CargoHold(unsigned int id) : DurableComponent(id),
        m_max_mass(0.0), m_current_mass(0.0), m_volume(0.0) 
{}

CargoHold::CargoHold(const CargoHold& orig) : 
        DurableComponent(orig.m_object_name, orig.m_object_id, orig.m_object_mass, 
                orig.m_cost, orig.m_durability_points),
         m_max_mass(orig.m_max_mass),
         m_current_mass(orig.m_current_mass),
         m_volume(orig.m_volume)
{
    CargoHold::DurableComponent(static_cast<DurableComponent const&>(orig));
}

CargoHold::~CargoHold() {}

CargoHold & CargoHold::operator =(const CargoHold& cargoHold) {
    if(this == &cargoHold) return *this;
    
    DurableComponent::operator =(static_cast<DurableComponent const&>(cargoHold));
    m_max_mass     = cargoHold.m_max_mass;
    m_current_mass = cargoHold.m_current_mass;
    m_volume       = cargoHold.m_volume;
    
    return *this;
}

}
