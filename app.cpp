#include "app.h"
#include <iostream>
#include <object.h>

using namespace std;

App * App::g_Instance = 0;

App::App(int argc, char **argv):
    Object(this),
    m_Args(argv, argv+argc),
    m_AtEnd(false)
{
    if ( g_Instance == 0 ){
        g_Instance = this;
    } else {
        throw SingleApplicationException();
    }
#ifdef _DEBUG
    std::cout << "Args: " << std::endl;
    std::copy( m_Args.begin(), m_Args.end(), std::ostream_iterator<String>(std::cout, "\n") );
#endif
}

int App::exec()
{
    int res = 0;
    while ( !m_AtEnd ) {
        EventList events = getEvents();
        for ( auto e = events.begin(); e != events.end(); ++e ){
            if (!event(**e)){
                cerr << "Ignored event: " << (*e)->type() << endl;
            }
        }
    }
    return res;
}

StringList App::args() const
{
    return m_Args;
}

void App::sendEvent(Event event)
{
    std::unique_lock<Mutex> lock(m_Mutex);
    m_Events.push_back(event);
    m_Condition.notify_all();
}

App *App::instance()
{
    return g_Instance;
}

bool App::exitEvent(const ExitEvent &)
{
    m_AtEnd = true;
    return false;
}

EventList App::getEvents()
{
    EventList res;
    std::unique_lock<Mutex> lock(m_Mutex);
    if ( m_Events.empty() ){
        m_Condition.wait(lock);
    }
    res = m_Events;
    m_Events.clear();
    return res;
}
