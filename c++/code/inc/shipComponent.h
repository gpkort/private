/* 
 * File:   shipComponent.h
 * Author: Greg Korthuis
 *
 * Created on October 6, 2013, 9:35 AM
 */

#ifndef SHIPCOMPONENT_H
#define	SHIPCOMPONENT_H

#include "GameObject.h"

class shipComponent : GameObject{
public:
    shipComponent();
    shipComponent(const shipComponent& orig);
    virtual ~shipComponent();
    
    
    void f() {};
private:
    float m_cost;
};

#endif	/* SHIPCOMPONENT_H */

