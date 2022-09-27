#ifndef MAPOBJECT_H
#define MAPOBJECT_H


class MapObject
{
public:
    virtual void changeStatus() = 0;
    virtual ~MapObject() = default;
};

#endif // MAPOBJECT_H
