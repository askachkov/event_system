#include "engine.h"
#include <iostream>

using namespace std;

Engine::Engine(Object *parent):
    Object(parent),
    m_Reader(new InputReader(this)),
    m_Display(0)
{

}

Engine::~Engine()
{
    cout << "~Engine" << endl;
}

bool Engine::inputEvent(const InputEvent &e)
{
    String str = e.getData();
    if ( str == "display-on" && m_Display == NULL ){
        m_Display = new Display(this);
        return true;
    }
    if ( str == "display-off" && m_Display != NULL ){
        delete m_Display;
        m_Display = NULL;
        return true;
    }
    if ( e.getData() == "except" ){
        throw std::exception("except-str");
    }
    return false;
}
