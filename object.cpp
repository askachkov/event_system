#include "object.h"
#include "app.h"

Object::Object(Object *parent):
    m_Parent(parent)
{
    if ( m_Parent ){
        m_Parent->addChild(this);
    } else {
        App::instance()->addChild(this);
    }
}

bool Object::event(const IEvent &e)
{
    bool res = false;
    for ( auto i = m_Children.begin(); i != m_Children.end(); ++i ){
        if ((*i)->event(e)){
            res = true;
        }
    }
    return res;
}

Object::Object(App *)
{
}

Object::~Object()
{
    for ( auto i = m_Children.begin(); i != m_Children.end(); ++i ){
        delete *i;
    }
}

void Object::addChild(Object *o)
{
    m_Children.insert(o);
}

