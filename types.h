#ifndef TYPES
#define TYPES

#include <string>
#include <vector>
#include <exception>
#include <iterator>
#include <algorithm>
#include <set>
#include <memory>
#include <deque>
#include <mutex>
#include <condition_variable>

class Object;

typedef std::string String;
typedef std::vector<String> StringList;
//typedef std::shared_ptr<Object> SharedObject;
//typedef std::weak_ptr<Object> WeakObject;
//typedef std::set<SharedObject> Children;
typedef std::set<Object*> Children;

class SingleApplicationException: public std::exception
{
public:
    SingleApplicationException(): std::exception("Should be create only one App instance"){}
};

class IEvent
{
public:
    virtual ~IEvent(){}
    virtual int type()const = 0;
};

enum EventType {
    CLOSE_APP_EVENT,
    INPUT_EVENT
};

class ExitEvent: public IEvent
{
public:
    virtual int type()const
    {
        return CLOSE_APP_EVENT;
    }
};

class InputEvent: public IEvent
{
public:
    InputEvent(const String & data): m_Data(data){}
    virtual int type()const
    {
        return INPUT_EVENT;
    }
    String getData()const
    {
        return m_Data;
    }

private:
    String m_Data;
};

typedef std::shared_ptr<IEvent> Event;
typedef std::deque<Event> EventList;

typedef std::mutex Mutex;
typedef std::condition_variable ConditionVar;

#endif // TYPES

