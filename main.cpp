#include <app.h>
#include <iostream>
#include "object.h"
#include <memory>
#include "inputreader.h"
#include "display.h"

using namespace std;

int main(int argc, char * argv[])
{
    int res = 0;
    try {
        App app(argc, argv);
        SharedObject arr[2] = {
            Object::New<InputReader>(),
            Object::New<Display>()
        };

        res = app.exec();
    } catch ( std::exception & e ) {
        cout << "Exception: " << e.what() << endl;
    }
    return res;
}
