#ifndef CXMLDATAMANAGER_H
#define CXMLDATAMANAGER_H

#include "ixmldatamanager.h"
#include "citerator.h"
#include <vector>
#include "crouteevent.h"
#include "seventdata.h"


class CXmlDataManager : public IXmlDataManager
{
public:
    CXmlDataManager(const QString& filePath);

    virtual CIterator<CRouteEvent>& getRouteEvents();
    virtual void prepareRouteEvents(const QString& filePath);
    virtual bool isReady() const;

    virtual ~CXmlDataManager();

private:
    vector<CRouteEvent> vectorRouteEvents;
    CIterator<CRouteEvent> iteratorRouteEvents;

    virtual void buildRouteEventsFromComponents(const shared_ptr<IXmlComponent> components);
};

#endif // CXMLDATAMANAGER_H
