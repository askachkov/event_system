TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11

SOURCES += main.cpp \
    app.cpp \
    object.cpp \
    inputreader.cpp \
    display.cpp \
    engine.cpp

HEADERS += \
    app.h \
    types.h \
    object.h \
    inputreader.h \
    display.h \
    engine.h


win32: LIBS += -L$$PWD/../build-dll_check-Desktop_Qt_5_5_1_MSVC2013_32bit-Debug/debug/ -ldll_check


#win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../build-dll_check-Desktop_Qt_5_5_1_MSVC2013_32bit-Debug/debug/dll_check.lib
#else:win32-g++: PRE_TARGETDEPS += $$PWD/../build-dll_check-Desktop_Qt_5_5_1_MSVC2013_32bit-Debug/debug/libdll_check.a
