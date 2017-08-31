#ifndef CXMLDATAMANAGER_H
#define CXMLDATAMANAGER_H

#include "ixmldatamanager.h"
#include "citerator.h"
#include <vector>


class CXmlDataManager : public IXmlDataManager
{
public:
    CXmlDataManager();

    virtual CIterator<CRouteEvent>& getRouteEvents();
    virtual bool prepareRouteEvents(const QString& filePath)const;

    virtual ~CXmlDataManager();

private:
    vector<CRouteEvent> vectorRouteEvents;
    CIterator<CRouteEvent> iteratorRouteEvents;
};

#endif // CXMLDATAMANAGER_H
