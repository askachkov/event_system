#include "display.h"
#include <iostream>

using namespace std;

Display::Display(Object *parent):
    Object(parent)
{

}

bool Display::event(const IEvent &e)
{
    if ( e.type() == INPUT_EVENT ){
        String str = reinterpret_cast<const InputEvent&>(e).getData();
        cout << "MSG:" << str << endl;
    }
    return Object::event(e);
}

Display::~Display()
{
    cout << "~Display" << endl;
}
