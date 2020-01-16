#ifndef ENGINE_H
#define ENGINE_H

#include "inputreader.h"
#include "display.h"

class Engine: public Object
{
public:
    explicit Engine(Object * parent = 0);
    ~Engine();

protected:
    bool inputEvent(const InputEvent &e);

private:
    InputReader * m_Reader;
    Display *     m_Display;
};

#endif // ENGINE_H
