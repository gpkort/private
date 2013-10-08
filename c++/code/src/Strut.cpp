/* 
 * File:   Strut.cpp
 * Author: Greg
 * 
 * Created on October 7, 2013, 6:42 PM
 */

#include "Strut.h"
#include "DurableComponent.h"

Strut::Strut() : m_length(0.0){ }

Strut::Strut(const Strut& orig) {
    Strut::DurableComponent(static_cast<DurableComponent const&>(orig));
    m_length = orig.m_length;
}

Strut::~Strut() { }

Strut& Strut::operator =(const Strut& strut) {
    DurableComponent::operator =(static_cast<DurableComponent const&>(strut));
    return *this;
}

