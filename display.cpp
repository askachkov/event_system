#include "display.h"
#include <iostream>

using namespace std;

Display::Display(Object *parent):
    Object(parent)
{

}

bool Display::event(const IEvent &e)
{
    if ( (e.type() == INPUT_EVENT) && inputEvent(e.as<InputEvent>()) ){
        return true;
    }
    return Object::event(e);
}

Display::~Display()
{
    cout << "~Display" << endl;
}

bool Display::inputEvent(const InputEvent &e)
{
    String str = e.getData();
    cout << "MSG:" << str << endl;
    return true;
}
