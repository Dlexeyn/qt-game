#ifndef EVENT_H
#define EVENT_H

class Event
{
public:
    virtual void trigger() = 0;
    virtual ~Event() = default;
};




#endif // EVENT_H
