/* 
 * File:   ManueveringComponent.cpp
 * Author: Greg
 * 
 * Created on October 9, 2013, 6:58 PM
 */

#include "ManueveringComponent.h"

namespace Model
{
   ManueveringComponent::~ManueveringComponent() { }
    
    bool ManueveringComponent::set_max_thrust(double thrust) {
        bool retval = false;
        
        if(thrust >= 0) {
            retval = true;
            m_max_thrust = thrust; 
       }        
        return retval;
    }
    
    bool ManueveringComponent::set_percent_thrust(double thrust) {
        bool retval = false;
        
        if(thrust >= 0) {
            retval = true;
            m_percent_thrust = thrust; 
       }        
        return retval;
    }
    
    bool ManueveringComponent::insert_thrust_curve_point(int percentThrust, double burnRate) {
        std::pair<std::map<int, double>::iterator, bool> ret;
        m_thrust_curve.insert(std::pair<int, double>(percentThrust, burnRate));
        return ret.second;
    }
    
    double ManueveringComponent::get_burn_rate(int percentOfThrust) {
        double retval = -1.0;
        
        if(!m_thrust_curve.empty()) {
            std::map<int, double>::iterator itr = m_thrust_curve.find(percentOfThrust);
            if( itr != m_thrust_curve.end()) 
                retval = itr->second;
            else {
                double x0, y0, x1, y1;
                itr = m_thrust_curve.lower_bound(percentOfThrust);
                x0 = itr->first;
                y0= itr->second;
                itr = m_thrust_curve.upper_bound(percentOfThrust);
                x1 = itr->first;
                y1= itr->second;
                
                double m = (y1-y0) / (x1- x0);
                double b = y0 - (m*x0);
                retval = percentOfThrust * m + b;
            }
        }
        return retval;
    }

}

