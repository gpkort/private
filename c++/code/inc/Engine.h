/* 
 * File:   Engine.h
 * Author: Jack
 *
 * Created on October 11, 2013, 3:54 PM
 */

#ifndef ENGINE_H
#define	ENGINE_H

#include "ManueveringComponent.h"
#include "CrashPadUtils.h"

namespace Model
{
class Engine : public ManueveringComponent{
public:
    Engine();
    Engine(const Engine& orig);
    virtual ~Engine();
    
    Engine & operator =(const Engine& engine);
    
    virtual ENGINE_TYPE get_engine_type() {return m_engine_type;};
    virtual void set_engine_type(ENGINE_TYPE engineType) {};
    
    
    
private:

};
}

#endif	/* ENGINE_H */

