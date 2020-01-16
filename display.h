#ifndef DISPLAY_H
#define DISPLAY_H

#include "object.h"

class Display:
        public Object
{
public:
    explicit Display(Object * parent = 0);
    ~Display();

protected:
    virtual bool inputEvent(const InputEvent & e);

    std::vector<Display *>     m_Displays;
};


#endif // DISPLAY_H
