/* 
 * File:   shipComponent.h
 * Author: Greg Korthuis
 *
 * Created on October 6, 2013, 9:35 AM
 */

#ifndef SHIPCOMPONENT_H
#define	SHIPCOMPONENT_H

#include "GameObject.h"
#include <cstdlib>

namespace Model
{
class ShipComponent : public GameObject {
public:
    ShipComponent();
    ShipComponent(unsigned int id);
    ShipComponent(const ShipComponent& orig);
    ShipComponent(std::string name, unsigned int id, double mass, float cost);
    
    ShipComponent & operator=(const ShipComponent& shipComponent);
    bool operator==(ShipComponent& rhs) const;
    
    inline float get_cost() { return m_cost; };
    inline void  set_cost(float cost) { m_cost = cost; };
    
    virtual ~ShipComponent();    
    
protected:
    float m_cost;
};
}
#endif	/* SHIPCOMPONENT_H */

