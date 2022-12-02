#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "Field.h"
#include "log/LogObject.h"
#include "GeneratorError.h"
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
        try {
            (modifyMap<Rules...>());
        } catch (errors::GeneratorError &er) {
            notifySubscribers("MapGenerator: " + std::string(er.what()), "global");
            newField.setIsGenerated(false);
        }
        return newField;
    }

private:
    map::Field newField;

    template <typename Rule, typename ... NextRules>
    void modifyMap()
    {
        Rule curRule;
        curRule.fill(newField);
        if constexpr (sizeof...(NextRules) > 0) {
            modifyMap<NextRules...>();
        }
    }
};

#endif // MAPGENERATOR_H
