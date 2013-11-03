/* 
 * File:   Pad.cpp
 * Author: Greg
 * 
 * Created on October 7, 2013, 4:17 PM
 */

#include "Pad.h"

namespace Model
{
Pad::Pad() : m_pad_area(0.0) { }

Pad::Pad(std::string name, unsigned int id, double mass, float cost, int points, double area) 
        : m_pad_area(area) 
{
    Pad::DurableComponent(name, id, mass, cost, points);
}
Pad::Pad(const Pad& orig) : m_pad_area(orig.m_pad_area) {
    Pad::DurableComponent(static_cast<DurableComponent const&>(orig));
}

Pad& Pad::operator =(const Pad& pad) {
     DurableComponent::operator =(static_cast<DurableComponent const&>(pad));
     m_pad_area = pad.m_pad_area;
     
     return *this;
}

Pad::~Pad() { }
}

