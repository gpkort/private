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
                ShipComponent(),
                m_fuel_curve(),
                m_thrust_curve(),
                m_nozzel_direction(),
                m_percent_thrust(0.0),
                m_engine_type(UNDEFINED_ENGINE),
                m_has_calculated_fuel(false),
                m_has_calculated_thrust(false),
                m_fuel_slope(0.0),
                m_fuel_intercept(0.0),
                m_thrust_slope(0.0),
                m_thrust_intercept(0.0)
        {};
        
        ManueveringComponent(unsigned int id) :
                ShipComponent(id),
                m_fuel_curve(),
                m_thrust_curve(),
                m_nozzel_direction(),
                m_percent_thrust(0.0),
                m_engine_type(UNDEFINED_ENGINE),
                m_has_calculated_fuel(false),
                m_has_calculated_thrust(false),
                m_fuel_slope(0.0),
                m_fuel_intercept(0.0),
                m_thrust_slope(0.0),
                m_thrust_intercept(0.0)
        {};
        
        virtual ~ManueveringComponent();
        
        virtual ENGINE_TYPE get_engine_type() { return m_engine_type; };
        virtual void set_engine_type(ENGINE_TYPE engineType) = 0;
        
        bool insert_thrust_curve_point(unsigned int percentThrust, double thrust);
        bool insert_fuel_curve_point(unsigned int percentThrust, double burnRate);
        
        bool set_percent_thrust(double thrust);      
        double get_burn_rate(double percentOfThrust);
        double get_amount_consumed(double percentOfThrust, double timedelta);
        double get_thrust(double percentOfThrust);
        
    protected:
        std::map<int, double>    m_fuel_curve; //first value is % of total thrust, second burn rate
        std::map<int, double>    m_thrust_curve; //first value is % of total thrust, second burn rate
        DirectionVector          m_nozzel_direction;
        double                   m_percent_thrust;
        ENGINE_TYPE              m_engine_type;
        bool                     m_has_calculated_fuel;
        bool                     m_has_calculated_thrust;        
        double                   m_fuel_slope;
        double                   m_fuel_intercept; 
        double                   m_thrust_slope;
        double                   m_thrust_intercept;

    protected:
        void init_curve(double &slope, double &intercept, std::map<int, double>& curve);        
    };
}

#endif	/* MANUEVERINGCOMPONENT_H */

