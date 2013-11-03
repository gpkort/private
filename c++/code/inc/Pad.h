/* 
 * File:   Pad.h
 * Author: Greg
 *
 * Created on October 7, 2013, 4:17 PM
 */

#ifndef PAD_H
#define	PAD_H

#include "DurableComponent.h"

namespace Model 
{
class Pad : public DurableComponent 
{
public:
    Pad();
    Pad(std::string name, unsigned int id, double mass, float cost, int points, double area);
    Pad(const Pad& orig);
    Pad & operator=(const Pad& pad);
    virtual ~Pad();
    
    inline void   set_pad_area(double padArea){ m_pad_area = padArea; }
    inline double get_pad_area() {return m_pad_area;}
private:
    double m_pad_area;
};
}
#endif	/* PAD_H */

