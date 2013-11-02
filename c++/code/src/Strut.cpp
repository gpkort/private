/* 
 * File:   Strut.cpp
 * Author: Greg
 * 
 * Created on October 7, 2013, 6:42 PM
 */

#include "Strut.h"
#include "DurableComponent.h"

namespace Model
{
Strut::Strut() : m_length(0.0){ }

Strut::Strut(const Strut& orig):  m_length(orig.m_length) {
    Strut::DurableComponent(static_cast<DurableComponent const&>(orig));   
}

Strut::~Strut() { }

Strut& Strut::operator =(const Strut& strut) {
    DurableComponent::operator =(static_cast<DurableComponent const&>(strut));
    return *this;
}
}

