/* 
 * File:   ManueveringComponent.cpp
 * Author: Greg
 * 
 * Created on October 9, 2013, 6:58 PM
 */

#include "ManueveringComponent.h"
#include <cmath>

using namespace std;

namespace Model
{
   ManueveringComponent::~ManueveringComponent() { }
            
    bool ManueveringComponent::set_percent_thrust(double thrust) {
        bool retval = false;
        
        if(thrust >= 0) {
            retval = true;
            m_percent_thrust = thrust; 
       }        
        return retval;
    }
    
    bool ManueveringComponent::insert_thrust_curve_point(unsigned int percentThrust, double burnRate) {
        pair<std::map<int, double>::iterator, bool> ret;
        m_thrust_curve.insert(std::pair<int, double>(percentThrust, burnRate));
        return ret.second;
    }
    
    bool ManueveringComponent::insert_fuel_curve_point(unsigned int percentThrust, double burnRate) {
        pair<std::map<int, double>::iterator, bool> ret;
        m_fuel_curve.insert(std::pair<int, double>(percentThrust, burnRate));
        return ret.second;
    }
    
    double ManueveringComponent::get_amount_consumed(double percentOfThrust, double timedelta) {
        return get_burn_rate(percentOfThrust) * timedelta;
    }
    
    double ManueveringComponent::get_burn_rate(double percentOfThrust) {
        if(!m_has_calculated_fuel) {
            init_curve(m_fuel_slope, m_fuel_intercept, m_fuel_curve);
            m_has_calculated_fuel = true;
        }
        
        return (m_fuel_slope * percentOfThrust + m_fuel_intercept);
    }
    
    double ManueveringComponent::get_thrust(double percentOfThrust) {
        if(!m_has_calculated_thrust) {
            init_curve(m_thrust_slope, m_thrust_intercept, m_thrust_curve);
            m_has_calculated_thrust = true;
        }
        
        return (m_thrust_slope * percentOfThrust + m_thrust_intercept);
    }
    
    void ManueveringComponent::init_curve(double &slope, double &intercept, map<int, double>& curve) {
        double sx = 0.0, sy = 0.0, sxx = 0.0, syy = 0.0, sxy = 0.0;
        int n = 0;
        
        if(!curve.empty()) {
            map<int, double>::iterator itr;
            for(itr = curve.begin(); itr != curve.end(); ++itr) {
                sx += itr->first;
                sy += itr->second;
                sxx += pow(itr->first, 2.0);
                syy += pow(itr->second, 2.0);
                sxy += (itr->first * itr->second);
                n++;
            }
            slope = ((n * sxy) - (sx * sy)) / ((n* sxx) - pow(sx, 2.0));
            intercept = (sy/n) - (slope/n * sx);            
        }
    }

}

