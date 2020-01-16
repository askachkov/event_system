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

void Object::sendEvent(Event event)
{
    App::instance()->sendEvent(event);
}

bool Object::event(const IEvent &e)
{
    bool res = false;
    if ( (e.type() == INPUT_EVENT) && inputEvent(e.as<InputEvent>()) ){
        return true;
    }
    if ( (e.type() == CLOSE_APP_EVENT) && exitEvent(e.as<ExitEvent>()) ){
        return true;
    }
    for ( auto i = m_Children.begin(); i != m_Children.end(); ++i ){
        if ((*i)->event(e)){
            res = true;
        }
    }
    return res;
}

bool Object::inputEvent(const InputEvent &)
{
    return false;
}

bool Object::exitEvent(const ExitEvent &)
{
    return false;
}

Object::Object(App *): m_Parent(0)
{
}

Object::~Object()
{
    if ( m_Parent  ){
        auto it = m_Parent->m_Children.find(this);
        if ( it != m_Parent->m_Children.end() ){
            m_Parent->m_Children.erase(it);
        }
    }
    Children  toDelete = m_Children;
    m_Children.clear();
    for ( Object * child: toDelete ){
        delete child;
    }
}

void Object::addChild(Object *o)
{
    m_Children.insert(o);
}

