#ifndef OBJECT_H
#define OBJECT_H

#include <types.h>

class App;

class Object
{
private:
    void addChild(Object * o);

public:
    Object(Object * parent);
    void sendEvent(Event event);
    virtual ~Object();

protected:
    Object(App*a);
    virtual bool event(const IEvent & e);
    virtual bool inputEvent(const InputEvent &e);
    virtual bool exitEvent(const ExitEvent &e);

private:
    Object *  m_Parent;
    Children  m_Children;
};

#endif // OBJECT_H
