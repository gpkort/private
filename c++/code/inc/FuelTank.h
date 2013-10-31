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
    FuelTank(const FuelTank& orig);
    FuelTank & operator=(const FuelTank& fuelTank);
    virtual ~FuelTank();
    
    inline double get_total_capacity() { return m_total_capacity; }
    inline void   set_total_capacity(double totalCapacity) { m_total_capacity = totalCapacity; }
    
    inline double get_current_capacity() { return m_current_amount; }
    inline void   set_current_capacity(double currentCapacity) { m_current_amount = currentCapacity; }
    
    inline FUEL_TYPE get_fuel_type() { return m_fuel_type; }
    inline void   set_fuel_type(FUEL_TYPE fuelType) { m_fuel_type = fuelType; }
    
private:
    double m_total_capacity;
    double m_current_amount;
    FUEL_TYPE m_fuel_type;
};
}
#endif	/* FUELTANK_H */

