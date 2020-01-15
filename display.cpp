#include "display.h"
#include <iostream>

using namespace std;

Display::Display(WeakObject parent):
    Object(parent)
{

}

bool Display::event(const IEvent &e)
{
    if ( e.type() == INPUT_EVENT ){
        cout << "MSG:" << reinterpret_cast<const InputEvent&>(e).getData() << endl;
    }
    return Object::event(e);
}

Display::~Display()
{

}
