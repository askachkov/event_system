#ifndef APP_H
#define APP_H

#include "types.h"
#include "object.h"

class App: public Object
{
    static App * g_Instance;
public:
    App(int argc, char ** argv);
    int exec();
    StringList args()const;
    void sendEvent(Event event);

public:
    static App* instance();
    bool exitEvent(const ExitEvent &);

private:
    EventList getEvents();

private:
    StringList      m_Args;
    bool            m_AtEnd;
    EventList       m_Events;
    Mutex           m_Mutex;
    ConditionVar    m_Condition;
};

#endif // APP_H
