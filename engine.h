#ifndef ENGINE_H
#define ENGINE_H

#include "inputreader.h"
#include "display.h"

class Engine: public Object
{
public:
    explicit Engine(WeakObject parent = WeakObject());

protected:
    ~Engine();

private:
//    SharedInputReader   m_Reader;
//    SharedDisplay       m_Display;
};

#endif // ENGINE_H
