/* 
 * File:   Pad.cpp
 * Author: Greg
 * 
 * Created on October 7, 2013, 4:17 PM
 */

#include "Pad.h"

namespace Model
{
Pad::Pad() : DurableComponent(), m_pad_area(0.0) { }

Pad::Pad(unsigned int id) : DurableComponent(id), m_pad_area(0.0) {}

Pad::Pad(std::string name, unsigned int id, double mass, float cost, int points, double area) 
        : DurableComponent(name, id, mass, cost, points), m_pad_area(area) 
{}
Pad::Pad(const Pad& orig) :
        DurableComponent(orig.m_object_name, orig.m_object_id, orig.m_object_mass, 
                orig.m_cost, orig.m_durability_points), m_pad_area(orig.m_pad_area) 
{ 
    int x = 0;
}

Pad& Pad::operator =(const Pad& pad) {
    if(this == &pad) return *this;
    
     DurableComponent::operator =(static_cast<DurableComponent const&>(pad));
     m_pad_area = pad.m_pad_area;
     
     return *this;
}


bool Pad::operator==(Pad & rhs) const {
    return (
            m_object_name       == rhs.m_object_name       &&
            m_object_id         == rhs.m_object_id         &&
            m_object_mass       == rhs.m_object_mass       &&
            m_cost              == rhs.m_cost              &&
            m_durability_points == rhs.m_durability_points &&
            m_pad_area          == rhs.m_pad_area
    );
}
 

Pad::~Pad() { }
}
