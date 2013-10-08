
#include "DurableComponent.h"

DurableComponent::DurableComponent() : m_durability_points(0.0F) {}

DurableComponent::DurableComponent(const DurableComponent& orig) {
    DurableComponent::ShipComponent(static_cast<ShipComponent const&>(orig));
    m_durability_points = orig.m_durability_points;
}

DurableComponent::~DurableComponent() {};

DurableComponent & DurableComponent::operator =(const DurableComponent& durableComponent) {
     GameObject::operator =(static_cast<GameObject const&>(durableComponent));
     this->m_durability_points = durableComponent.m_durability_points;
     
     return *this;
}
