/* 
 * File:   GameObject.h
 * Author: Greg Korthuis
 * concrete class for for all game objects
 *
 * Created on October 6, 2013, 8:48 AM
 */

#ifndef GAMEOBJECT_H
#define	GAMEOBJECT_H

#include <cstdlib>
#include <string>

namespace Model {
class GameObject {
public:
    inline void set_object_name(std::string objectName) {m_object_name = objectName;}
    inline std::string get_object_name() { return m_object_name; } 
    
    inline void set_object_id(unsigned int objectID) { m_object_id = objectID; }
    inline unsigned int get_object_id() { return m_object_id; }
    
    virtual void set_object_mass(double objectMass) { m_object_mass = objectMass; }
    virtual double get_object_mass() { return m_object_mass; }
    
        
    GameObject() : m_object_name(""), m_object_id(0), m_object_mass(0.0){ };
    
    GameObject(unsigned int id) : m_object_name(""), m_object_id(id), m_object_mass(0.0){ };
    
    GameObject(std::string name, unsigned int id, double mass) :
        m_object_name(name), m_object_id(id), m_object_mass(mass) 
    { };
        
    GameObject(const GameObject& other) :
        m_object_name(other.m_object_name),
        m_object_id(other.m_object_id),
        m_object_mass(other.m_object_mass)
        {}
    
    GameObject & operator=(const GameObject& gameObject) {
        m_object_name = gameObject.m_object_name;
        m_object_id   = gameObject.m_object_id;
        m_object_mass = gameObject.m_object_mass;
        return(*this);
    }
    
    bool operator==(GameObject& rhs) const {
        return (
            m_object_name == rhs.m_object_name &&
            m_object_id   == rhs.m_object_id &&
            m_object_mass == rhs.m_object_mass
        );        
    }
    
    
    virtual ~GameObject() {};
    
protected:
    std::string         m_object_name;
    unsigned int        m_object_id;
    double              m_object_mass;
};
}
#endif	/* GAMEOBJECT_H */

