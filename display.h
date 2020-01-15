#ifndef DISPLAY_H
#define DISPLAY_H

#include "object.h"

class Display:
        public Object
{
public:
    explicit Display(WeakObject parent = WeakObject());
    virtual bool event(const IEvent & e);

protected:
    ~Display();
};

typedef std::shared_ptr<Display> SharedDisplay;

#endif // DISPLAY_H
