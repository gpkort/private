/* 
 * File:   FuelTank.cpp
 * Author: Jack
 * 
 * Created on October 7, 2013, 6:56 PM
 */

#include "FuelTank.h"

namespace Model
{
FuelTank::FuelTank(): m_total_capacity(0.0), m_current_amount(0.0),
                      m_fuel_type(UNDEFINED_FUEL), m_fuel_density(0.0) 
{}

FuelTank::FuelTank(std::string name, unsigned int id, double mass, float cost,
                   int points, double capacity, double currentAmount, 
                   FUEL_TYPE fuelType, double fuelDensity)
        : DurableComponent(name, id, mass, cost, points), 
          m_total_capacity(capacity), m_current_amount(currentAmount),
          m_fuel_type(fuelType), m_fuel_density(fuelDensity)
{ }

FuelTank::FuelTank(const FuelTank& orig) :    
    m_total_capacity(orig.m_total_capacity),
    m_current_amount(orig.m_current_amount),
    m_fuel_type(orig.m_fuel_type),
    m_fuel_density(orig.m_fuel_density)
{
    FuelTank::DurableComponent(static_cast<DurableComponent const&>(orig));
}

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

double FuelTank::get_object_mass() {
    return (m_object_mass + (m_total_capacity * m_current_amount * m_fuel_density));
}

}



