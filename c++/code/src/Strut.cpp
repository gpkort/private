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

Strut::Strut(unsigned int id) : DurableComponent(id), m_length(0.0) {}

Strut::Strut(const Strut& orig):  
        DurableComponent(orig.m_object_name, orig.m_object_id, orig.m_object_mass, 
                orig.m_cost, orig.m_durability_points), m_length(orig.m_length) {}

Strut::~Strut() { }

Strut& Strut::operator =(const Strut& strut) {
    if(this == &strut) return *this;
    
    DurableComponent::operator =(static_cast<DurableComponent const&>(strut));
    return *this;
}

bool Strut::operator==(Strut & rhs) const {
    return (
            m_object_name       == rhs.m_object_name       &&
            m_object_id         == rhs.m_object_id         &&
            m_object_mass       == rhs.m_object_mass       &&
            m_cost              == rhs.m_cost              &&
            m_durability_points == rhs.m_durability_points &&
            m_length            == rhs.m_length
    );
}

}

