#include "engine.h"
#include <iostream>

using namespace std;

Engine::Engine(Object *parent):
    Display(parent),
    m_Reader(new InputReader(this)),
    m_Display(new Display(this))
{

}

Engine::~Engine()
{
    cout << "~Engine" << endl;
}

bool Engine::inputEvent(const InputEvent &e)
{
    if ( e.getData() == "except" ){
        throw std::exception("except-str");
    }
    return false;
}
