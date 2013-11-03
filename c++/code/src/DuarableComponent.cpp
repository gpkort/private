
#include "DurableComponent.h"

namespace Model
{
DurableComponent::DurableComponent() : m_durability_points(0.0F) {}

DurableComponent::DurableComponent(std::string name, unsigned int id, 
        double mass, float cost, int points) :
        ShipComponent(name, id, mass, cost), m_durability_points(points) 
{ }

DurableComponent::DurableComponent(const DurableComponent& orig) :
        m_durability_points(orig.m_durability_points)
{
    DurableComponent::ShipComponent(static_cast<ShipComponent const&>(orig));    
}

DurableComponent::~DurableComponent() {};

DurableComponent & DurableComponent::operator =(const DurableComponent& durableComponent) {
     GameObject::operator =(static_cast<GameObject const&>(durableComponent));
     this->m_durability_points = durableComponent.m_durability_points;
     
     return *this;
}
}
