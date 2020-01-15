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
    virtual bool event(const IEvent & e);

protected:
    Object(App*a);
    virtual ~Object();

private:
    Object *  m_Parent;
    Children  m_Children;
};

#endif // OBJECT_H
