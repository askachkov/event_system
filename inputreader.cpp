#include "inputreader.h"
#include "app.h"
#include <iostream>

using namespace std;

InputReader::InputReader(Object *parent):
    Object(parent),
    m_Future(async(launch::async,&InputReader::asyncWoker,this))
{

}

InputReader::~InputReader()
{
    cout << "~InputReader" << endl;
}

bool InputReader::asyncWoker()
{
    String buf;
    while ( cin >> buf ){
        if ( buf == "exit" ){
            sendEvent(Event(new ExitEvent));
        } else {
            sendEvent(Event(new InputEvent(buf)));
        }
    }
    return true;
}

