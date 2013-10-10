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
        ManueveringComponent();
        ManueveringComponent(const ManueveringComponent& orig);
        ManueveringComponent & operator=(const ManueveringComponent& comp);
        virtual ~ManueveringComponent();
        
        inline double get_max_thrust() {return m_max_thrust; }
        inline double get_percent_thrust() { return m_percent_thrust; }
        
        inline ENGINE_TYPE get_engine_type() { return m_engine_type; }
        inline void set_engine_type(ENGINE_TYPE engineType) {m_engine_type = engineType;};
        
        void insert_thrust_curve_point(double fuel, double thrust);
        bool set_max_thrust(double thrust);
        bool set_percent_thrust(double thrust);
        
    private:
        std::map<double, double> m_thrust_curve;
        DirectionVector          m_nozzel_direction;
        double                   m_max_thrust;
        double                   m_percent_thrust;
        ENGINE_TYPE              m_engine_type;
    };
}

#endif	/* MANUEVERINGCOMPONENT_H */

