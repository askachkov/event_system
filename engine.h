#ifndef ENGINE_H
#define ENGINE_H

#include "inputreader.h"
#include "display.h"

class Engine: public Display
{
public:
    explicit Engine(Object * parent = 0);

protected:
    ~Engine();
    bool inputEvent(const InputEvent &e);

private:
    InputReader * m_Reader;
    Display *     m_Display;
};

#endif // ENGINE_H
