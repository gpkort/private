/* 
 * File:   DurableComponent.h
 * Author: Greg
 *
 * Created on October 7, 2013, 1:52 PM
 */

#ifndef DURABLECOMPONENT_H
#define	DURABLECOMPONENT_H

#include "ShipComponent.h"

namespace Model
{
class DurableComponent : public ShipComponent {
public:
    DurableComponent();
    DurableComponent(const DurableComponent& orig);
    DurableComponent & operator=(const DurableComponent& durableComponent);
    
    virtual ~DurableComponent();
    
    inline int  get_durability_points(){ return m_durability_points; };
    inline void set_durability_points(int durabilityPoints){ m_durability_points = durabilityPoints;};
private:
    int m_durability_points;
};
}



#endif	/* DURABLECOMPONENT_H */

