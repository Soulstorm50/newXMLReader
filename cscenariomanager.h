#ifndef CSCENARIOMANAGER_H
#define CSCENARIOMANAGER_H

#include "iscenariomanager.h"
#include "citerator.h"
#include "crouteevent.h"

#include "cxmlcompositecomp.h"
#include "ixmlcomp.h"
#include "cxmlreader.h"
#include "seventdata.h"
#include "crouteevent.h"

#include "nfsm.h"

#include <vector>

using std::vector;

class CScenarioManager : public IScenarioManager
{
public:
    CScenarioManager();

    ~CScenarioManager();



    // IScenarioManager interface
public:
    virtual CIterator<CRouteEvent> &getEventIterator();
    virtual bool prepareScenario() const;


private:

    vector<CRouteEvent> m_routeEventCollection;
    CIterator<CRouteEvent> m_iterator;

    void initEvents(IXmlComp* component);

};

#endif // CSCENARIOMANAGER_H
