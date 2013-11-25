
#include "DurableComponent.h"

namespace Model
{
DurableComponent::DurableComponent() : m_durability_points(0.0F) {}

DurableComponent::DurableComponent(unsigned int id) : ShipComponent(id), m_durability_points(0.0F) {}

DurableComponent::DurableComponent(std::string name, unsigned int id, 
        double mass, float cost, int points) :
        ShipComponent(name, id, mass, cost), m_durability_points(points) 
{ }

DurableComponent::DurableComponent(const DurableComponent& orig) :
        ShipComponent(orig.m_object_name, orig.m_object_id, orig.m_object_mass, orig.m_object_mass), 
        m_durability_points(orig.m_durability_points)
{
    DurableComponent::ShipComponent(static_cast<ShipComponent const&>(orig));    
}

DurableComponent::~DurableComponent() {};

DurableComponent & DurableComponent::operator =(const DurableComponent& durableComponent) {
    if(this == &durableComponent) return *this;
    
     GameObject::operator =(static_cast<GameObject const&>(durableComponent));
     this->m_durability_points = durableComponent.m_durability_points;
     
     return *this;
}

bool DurableComponent::operator==(DurableComponent& rhs) const {
    return (
            m_object_name       == rhs.m_object_name &&
            m_object_id         == rhs.m_object_id   &&
            m_object_mass       == rhs.m_object_mass &&
            m_cost              == rhs.m_cost        &&
            m_durability_points == rhs.m_durability_points
    );
}

}
