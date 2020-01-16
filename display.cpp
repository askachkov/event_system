#include "display.h"
#include <iostream>

using namespace std;

Display::Display(Object *parent):
    Object(parent)
{

}

Display::~Display()
{
    cout << "~Display" << endl;
}

bool Display::inputEvent(const InputEvent &e)
{
    if ( e.getData() == "push" ){
        m_Displays.push_back(new Display(this));
        return true;
    }
    if ( e.getData() == "pop" && m_Displays.size() ){
        delete *m_Displays.rbegin();
        m_Displays.pop_back();
        return true;
    }

    String str = e.getData();

    cout << "MSG:" << str << endl;
    return false;
}
