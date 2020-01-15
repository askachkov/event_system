#ifndef DISPLAY_H
#define DISPLAY_H

#include "object.h"

class Display:
        public Object
{
public:
    explicit Display(Object * parent = 0);
    virtual bool event(const IEvent & e);

protected:
    ~Display();
    virtual bool inputEvent(const InputEvent & e);
};


#endif // DISPLAY_H
