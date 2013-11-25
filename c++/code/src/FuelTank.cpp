/* 
 * File:   FuelTank.cpp
 * Author: Jack
 * 
 * Created on October 7, 2013, 6:56 PM
 */

#include "FuelTank.h"

namespace Model
{
FuelTank::FuelTank(): DurableComponent(), m_total_capacity(0.0), m_current_amount(0.0),
                      m_fuel_type(UNDEFINED_FUEL), m_fuel_density(0.0) 
{}

FuelTank::FuelTank(unsigned int id):DurableComponent(id), m_total_capacity(0.0), 
        m_current_amount(0.0), m_fuel_type(UNDEFINED_FUEL), m_fuel_density(0.0) 
{ }

FuelTank::FuelTank(std::string name, unsigned int id, double mass, float cost,
                   int points, double capacity, double currentAmount, 
                   FUEL_TYPE fuelType, double fuelDensity)
        : DurableComponent(name, id, mass, cost, points), 
          m_total_capacity(capacity), m_current_amount(currentAmount),
          m_fuel_type(fuelType), m_fuel_density(fuelDensity)
{ }

FuelTank::FuelTank(const FuelTank& orig) : 
    DurableComponent(orig.m_object_name, orig.m_object_id, orig.m_object_mass, 
                orig.m_cost, orig.m_durability_points),
    m_total_capacity(orig.m_total_capacity),
    m_current_amount(orig.m_current_amount),
    m_fuel_type(orig.m_fuel_type),
    m_fuel_density(orig.m_fuel_density)
{}

FuelTank::~FuelTank() {}

FuelTank& FuelTank::operator =(const FuelTank& fuelTank) {
    if(this == &fuelTank) return *this;
    
     DurableComponent::operator =(static_cast<DurableComponent const&>(fuelTank));
      m_total_capacity = fuelTank.m_total_capacity;
      m_current_amount = fuelTank.m_current_amount;
      m_fuel_type      = fuelTank.m_fuel_type;
      m_fuel_density   = fuelTank.m_fuel_density; 
     
     return *this;
}

bool FuelTank::operator ==(FuelTank& rhs) const {
    return (
            m_object_name       == rhs.m_object_name       &&
            m_object_id         == rhs.m_object_id         &&
            m_object_mass       == rhs.m_object_mass       &&
            m_cost              == rhs.m_cost              &&
            m_durability_points == rhs.m_durability_points &&
            m_total_capacity    == rhs.m_total_capacity    &&
            m_current_amount    == rhs.m_current_amount    &&
            m_fuel_type         == rhs.m_fuel_type         &&
            m_fuel_density      == rhs.m_fuel_density
    );
}

double FuelTank::get_object_mass() {
    return (m_object_mass + (m_total_capacity * m_current_amount * m_fuel_density));
}

}



