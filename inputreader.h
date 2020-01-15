#ifndef INPUTREADER_H
#define INPUTREADER_H

#include "object.h"
#include <future>

class InputReader:
        public Object
{
public:
    explicit InputReader(Object * parent = 0);

protected:
    ~InputReader();

private:
    bool asyncWoker();

private:
    std::future<bool> m_Future;
};

#endif // INPUTREADER_H
