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

Pad::Pad(const Pad& orig) {
    Pad::DurableComponent(static_cast<DurableComponent const&>(orig));
    m_pad_area = orig.m_pad_area;
}

Pad& Pad::operator =(const Pad& pad) {
     DurableComponent::operator =(static_cast<DurableComponent const&>(pad));
     m_pad_area = pad.m_pad_area;
     
     return *this;
}

Pad::~Pad() { }
}

