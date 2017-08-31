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

    virtual CIterator<CRouteEvent>& getRouteEvents()const = 0;
    virtual bool prepareRouteEvents(const QString& filePath)const = 0;

    virtual ~IXmlDataManager();
};

#endif // IXMLDATAMANAGER_H
