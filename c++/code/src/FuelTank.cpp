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
                      m_fuel_type(FUEL_TYPE::UNDEFINED_FUEL) 
{}

FuelTank::FuelTank(const FuelTank& orig) {
    FuelTank::DurableComponent(static_cast<DurableComponent const&>(orig));
    m_total_capacity = orig.m_total_capacity;
    m_current_amount = orig.m_current_amount;
    m_fuel_type      = orig.m_fuel_type;
}

FuelTank::~FuelTank() {}

FuelTank& FuelTank::operator =(const FuelTank& fuelTank) {
     DurableComponent::operator =(static_cast<DurableComponent const&>(fuelTank));
      m_total_capacity = fuelTank.m_total_capacity;
      m_current_amount = fuelTank.m_current_amount;
      m_fuel_type      = fuelTank.m_fuel_type;
     
     return *this;
}

}



