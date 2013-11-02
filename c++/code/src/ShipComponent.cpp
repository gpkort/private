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

ShipComponent::ShipComponent(const ShipComponent& orig) : m_cost(orig.m_cost) {
    ShipComponent::GameObject(static_cast<GameObject const&>(orig));    
}

ShipComponent::~ShipComponent() { }

ShipComponent & ShipComponent::operator =(const ShipComponent& shipComponent) {
     GameObject::operator =(static_cast<GameObject const&>(shipComponent));
     m_cost = shipComponent.m_cost;
     
     return *this;
}
}

