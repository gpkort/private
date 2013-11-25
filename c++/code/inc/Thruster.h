/* 
 * File:   Thruster.h
 * Author: Jack
 *
 * Created on October 12, 2013, 7:21 PM
 */

#ifndef THRUSTER_H
#define	THRUSTER_H

#include "ManueveringComponent.h"
#include "CrashPadUtils.h"

namespace Model
{
class Thruster : public ManueveringComponent{
public:
    Thruster();
    Thruster(unsigned int id);
    Thruster(const Thruster& orig);
    virtual ~Thruster();
    
    Thruster & operator =(const Thruster& thruster);
    bool operator==(Thruster& rhs) const;
    
    //virtual ENGINE_TYPE get_engine_type() {return m_engine_type;};
    virtual void set_engine_type(ENGINE_TYPE engineType) {};
private:

};
}
#endif	/* THRUSTER_H */

