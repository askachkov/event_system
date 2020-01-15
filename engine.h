#ifndef ENGINE_H
#define ENGINE_H

#include "inputreader.h"
#include "display.h"

class Engine: public Object
{
public:
    explicit Engine(Object * parent = 0);

protected:
    ~Engine();

private:
    InputReader * m_Reader;
    Display *     m_Display;
};

#endif // ENGINE_H
