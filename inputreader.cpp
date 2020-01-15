#include "inputreader.h"
#include "app.h"
#include <iostream>

using namespace std;

InputReader::InputReader(WeakObject parent):
    Object(parent),
    m_Future(async(launch::async,&InputReader::woker,this))
{

}

InputReader::~InputReader()
{

}

bool InputReader::woker()
{
    String buf;
    while ( cin >> buf ){
        if ( buf == "exit" ){
            App::instance()->sendEvent(Event(new ExitEvent));
        } else {
            App::instance()->sendEvent(Event(new InputEvent(buf)));
        }
    }
    return true;
}

