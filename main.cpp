#include <app.h>
#include <iostream>
#include "object.h"
#include <memory>
#include "engine.h"

using namespace std;

int main(int argc, char * argv[])
{
    int res = 0;
    try {
        App app(argc, argv);
        Object* engine = new Engine();
        res = app.exec();
    } catch ( std::exception & e ) {
        cout << "Exception: " << e.what() << endl;
    } catch ( ... ){
        cout << "General error." << endl;
    }

    return res;
}
