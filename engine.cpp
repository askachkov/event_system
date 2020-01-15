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

