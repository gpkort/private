/* 
 * File:   Strut.h
 * Author: Greg
 *
 * Created on October 7, 2013, 6:42 PM
 */

#ifndef STRUT_H
#define	STRUT_H

#include "DurableComponent.h"

class Strut : public DurableComponent
{
public:
    Strut();
    Strut(const Strut& orig);
    Strut & operator=(const Strut& strut);
    virtual ~Strut();
    
    inline double get_length() { return m_length;};
    inline void   set_length(double length) { m_length = length; }
private:
    double m_length;
};

#endif	/* STRUT_H */

