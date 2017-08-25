#ifndef ISCENARIOMANAGER_H
#define ISCENARIOMANAGER_H

#include "crouteevent.h"
#include "citerator.h"

class IScenarioManager
{
public:
    IScenarioManager();

    virtual ~IScenarioManager();

    virtual CIterator<CRouteEvent>& getEventIterator() = 0;
    virtual bool prepareScenario()const = 0;


};

#endif // ISCENARIOMANAGER_H
