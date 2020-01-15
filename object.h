#ifndef OBJECT_H
#define OBJECT_H

#include <types.h>
#include "app.h"

class Object
{
private:
    void addChild(SharedObject o);

public:
    Object(WeakObject parent);
    virtual bool event(const IEvent & e);
    static void free(Object * o);
    template <typename T> static std::shared_ptr<T> New(WeakObject parent = WeakObject());

protected:
    virtual ~Object();

private:
    WeakObject  m_Parent;
    Children  m_Children;
};

template <typename T>
std::shared_ptr<T> Object::New(WeakObject parent)
{
    std::shared_ptr<T> res(new T(parent), [](Object * ptr){ Object::free(ptr); });
    auto shared = parent.lock();
    if ( shared ){
        shared->addChild(res);
    } else {
        App::instance()->addChild(res);
    }
    return res;
}

#endif // OBJECT_H
