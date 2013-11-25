/* 
 * File:   shipComponent.cpp
 * Author: Jack
 * 
 * Created on October 6, 2013, 9:35 AM
 */

#include "ShipComponent.h"

namespace Model
{
ShipComponent::ShipComponent() : m_cost(0.0) { }

ShipComponent::ShipComponent(unsigned int id) : GameObject(id), m_cost() { }

ShipComponent::ShipComponent(std::string name, unsigned int id, double mass, float cost) 
        : GameObject(name, id, mass), m_cost(cost)
{ }

ShipComponent::ShipComponent(const ShipComponent& orig) :
        GameObject(orig.m_object_name, orig.m_object_id, orig.m_object_mass),
        m_cost(orig.m_cost) 
{ }

ShipComponent::~ShipComponent() { }

ShipComponent & ShipComponent::operator =(const ShipComponent& shipComponent) {
    if(this == &shipComponent) return *this;
    
     GameObject::operator =(static_cast<GameObject const&>(shipComponent));
     m_cost = shipComponent.m_cost;
     
     return *this;
}

bool ShipComponent::operator==(ShipComponent& rhs) const {
    return (
            m_object_name == rhs.m_object_name &&
            m_object_id   == rhs.m_object_id   &&
            m_object_mass == rhs.m_object_mass &&
            m_cost        == rhs.m_cost
    );
}

}

