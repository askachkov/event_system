#include "object.h"
//#include <iostream>

Object::Object(WeakObject parent):
    m_Parent(parent)
{

}

bool Object::event(const IEvent &e)
{
    for ( auto i = m_Children.begin(); i != m_Children.end(); ++i ){
        (*i)->event(e);
    }
    return false;
}

Object::~Object()
{
//    std::cout << "Destroyed";
}

void Object::addChild(SharedObject o)
{
    m_Children.insert(o);
}

void Object::free(Object *o)
{
    delete o;
}

