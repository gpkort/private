/* 
 * File:   FuelTank.h
 * Author: Greg
 *
 * Created on October 7, 2013, 6:56 PM
 */

#ifndef FUELTANK_H
#define	FUELTANK_H

#include "DurableComponent.h"

class FuelTank : public DurableComponent 
{
public:
    FuelTank();
    FuelTank(const FuelTank& orig);
    FuelTank & operator=(const FuelTank& fuelTank);
    virtual ~FuelTank();
    
private:
    double m_capacity;
};

#endif	/* FUELTANK_H */

