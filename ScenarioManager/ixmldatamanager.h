#ifndef IXMLDATAMANAGER_H
#define IXMLDATAMANAGER_H

#include "citerator.h"
#include "crouteevent.h"
#include "ixmlcomponent.h"
#include "cxmlreader.h"
#include <memory>

using std::shared_ptr;
using namespace Nfsm;

class IXmlDataManager
{
public:

    virtual CIterator<CRouteEvent>& getRouteEvents() = 0;
    virtual void prepareRouteEvents(const QString& filePath) = 0;
    virtual bool isReady() const = 0;

    virtual ~IXmlDataManager();

private:

    virtual void buildRouteEventsFromComponents(const shared_ptr<IXmlComponent> components) = 0;

};

#endif // IXMLDATAMANAGER_H
