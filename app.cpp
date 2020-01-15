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
    std::unique_lock<Mutex> lock(m_Mutex);
    while ( !m_AtEnd ) {
        m_Condition.wait(lock);
        for ( auto e = m_Events.begin(); e != m_Events.end(); ++e ){
            if (!event(**e)){
                cerr << "Ignored event: " << (*e)->type() << endl;
            }
        }
        m_Events.clear();

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

bool App::event(const IEvent &e)
{
    if( e.type() == CLOSE_APP_EVENT ){
        m_AtEnd = true;
        return true;
    }
    return Object::event(e);
}
