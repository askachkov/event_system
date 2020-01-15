#ifndef INPUTREADER_H
#define INPUTREADER_H

#include "object.h"
#include <future>

class InputReader:
        public Object
{
public:
    explicit InputReader(WeakObject parent = WeakObject());

protected:
    ~InputReader();

private:
    bool woker();

private:
    std::future<bool> m_Future;
};

typedef std::shared_ptr<InputReader> SharedInputReader;

#endif // INPUTREADER_H
