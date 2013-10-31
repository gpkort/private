/* 
 * File:   CargoHold.h
 * Author: Jack
 *
 * Created on October 11, 2013, 9:37 AM
 */

#ifndef CARGOHOLD_H
#define	CARGOHOLD_H

#include "DurableComponent.h"

namespace Model {
class CargoHold : public DurableComponent {
public:
    CargoHold();
    CargoHold(const CargoHold& orig);
    CargoHold & operator=(const CargoHold& cargoHold);
    virtual ~CargoHold();
    
    inline double GetMaxMass() { return m_max_mass; }
    inline void SetMaxMass(double maxMass) {m_max_mass = maxMass;}
    
    inline double GetCurrentMass() { return m_current_mass; }
    inline void SetCurrentMass(double maxMass) {m_current_mass = maxMass;}
    
    inline double GetVolume() { return m_volume; }
    inline void SetVolume(double maxMass) {m_volume = maxMass;}
    
    
private:
    double m_max_mass;
    double m_current_mass;
    double m_volume;
};
}

#endif	/* CARGOHOLD_H */

