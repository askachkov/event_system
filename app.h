#ifndef APP_H
#define APP_H

#include "types.h"

class App
{
    static App * g_Instance;
public:
    App(int argc, char ** argv);
    int exec();
    StringList args()const;
    void addChild(SharedObject o);
    void sendEvent(Event event);

public:
    static App* instance();

private:
    bool event(const IEvent & e);

private:
    StringList m_Args;
    Children   m_Roots;
    bool       m_AtEnd;
    EventList  m_Events;
    Mutex      m_Mutex;
    ConditionVar m_Condition;
};

#endif // APP_H
