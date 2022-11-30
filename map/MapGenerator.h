#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "Field.h"
#include "log/LogObject.h"
#include <string>

template <typename ...Rules>
class MapGenerator: public LogObject
{
public:
    MapGenerator(){}
    map::Field generate(const std::vector<EventSubscriber *> &loggers)
    {
        subscribe(loggers);
        newField.setEventFactory(new CellEventFactory
                                (CellEventType::COLOR_BOX, loggers, nullptr));
        (modifyMap<Rules...>());
        if(err != "Ok")
            notifySubscribers("MapGenerator: " + err, "warning");
        else
        {
           notifySubscribers("MapGenerator: " + err, "global");
           newField.setIsGenerated(true);
        }

        return newField;

    }

private:
    map::Field newField;
    std::string err = "Ok";

    template <typename Rule, typename ... NextRules>
    void modifyMap()
    {
        Rule curRule;
        err = curRule.fill(newField);
        if(err != "Ok")
            return;
        if constexpr (sizeof...(NextRules) > 0) {
            modifyMap<NextRules...>();
        }
    }
};

#endif // MAPGENERATOR_H
