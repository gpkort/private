/* 
 * File:   ManueveringComponent.h
 * Author: Jack
 *
 * Created on October 9, 2013, 6:58 PM
 */

#ifndef MANUEVERINGCOMPONENT_H
#define	MANUEVERINGCOMPONENT_H

#include "CrashPadUtils.h"
#include "ShipComponent.h"
#include <map>

namespace Model
{
    class ManueveringComponent : public ShipComponent {
    public:
        ManueveringComponent() :
                m_thrust_curve(),
                m_nozzel_direction(),
                m_max_thrust(0.0),
                m_percent_thrust(0.0),
                m_engine_type(UNDEFINED_ENGINE)
        {};
        virtual ~ManueveringComponent();
        
        inline double get_max_thrust() {return m_max_thrust; }
        inline double get_percent_thrust() { return m_percent_thrust; }
        
        virtual ENGINE_TYPE get_engine_type() { return m_engine_type; };
        virtual void set_engine_type(ENGINE_TYPE engineType) = 0;
        
        bool insert_thrust_curve_point(int percentThrust, double burnRate);
        bool set_max_thrust(double thrust);
        bool set_percent_thrust(double thrust);
        double get_burn_rate(int percentOfThrust);
        double get_amount_consumed(double throttlePercent, double timedelta);
        
        
    protected:
        std::map<int, double>    m_thrust_curve; //first value is % of total thrust, second burn rate
        DirectionVector          m_nozzel_direction;
        double                   m_max_thrust;
        double                   m_percent_thrust;
        ENGINE_TYPE              m_engine_type;
    };
}

#endif	/* MANUEVERINGCOMPONENT_H */

