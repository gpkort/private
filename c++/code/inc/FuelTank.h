/* 
 * File:   FuelTank.h
 * Author: Greg
 *
 * Created on October 7, 2013, 6:56 PM
 */

#ifndef FUELTANK_H
#define	FUELTANK_H

#include "DurableComponent.h"
#include "CrashPadUtils.h"

namespace Model {
class FuelTank : public DurableComponent 
{
public:
    FuelTank();
    FuelTank(unsigned int id);
    FuelTank(std::string name, unsigned int id, 
             double mass, float cost, int points, double capacity,
             double currentAmount = 0.0, FUEL_TYPE fuelType = UNDEFINED_FUEL,
             double fuelDensity = 0.0);
    FuelTank(const FuelTank& orig);
    
    FuelTank & operator=(const FuelTank& fuelTank);
    bool operator==(FuelTank& rhs) const;
    virtual ~FuelTank();
    
    inline double get_total_capacity() { return m_total_capacity; }
    inline void   set_total_capacity(double totalCapacity) { m_total_capacity = totalCapacity; }
    
    inline double get_current_percent() { return m_current_amount; }
    inline void   set_current_percent(double currentCapacity) { m_current_amount = currentCapacity; }
    
    inline FUEL_TYPE get_fuel_type() { return m_fuel_type; }
    inline void   set_fuel_type(FUEL_TYPE fuelType) { m_fuel_type = fuelType; }
    
    inline double get_fuel_density() { return m_fuel_density; }
    inline void  set_fuel_density(double fuelDensity) { m_fuel_density = fuelDensity; }
    
    inline double get_remaining_fuel_units() { return m_total_capacity * m_current_amount; }
    
    double get_object_mass();
    
private:
    double m_total_capacity;    //liters
    double m_current_amount;    //rational 0 to 1.0
    FUEL_TYPE m_fuel_type;
    double m_fuel_density;      // kg per liter
};
}
#endif	/* FUELTANK_H */

