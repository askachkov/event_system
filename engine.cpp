#include "engine.h"
#include <iostream>

using namespace std;

Engine::Engine(Object *parent):
    Object(parent),
    m_Reader(new InputReader(this)),
    m_Display(new Display(this))
{

}

Engine::~Engine()
{
    cout << "~Engine" << endl;
}

bool Engine::event(const IEvent &e)
{
    if ( e.type() == INPUT_EVENT && e.as<InputEvent>().getData() == "except" ){
        throw std::exception("except-str");
    }
    return Object::event(e);
}

