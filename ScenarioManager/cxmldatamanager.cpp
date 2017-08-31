#include "cxmldatamanager.h"

CXmlDataManager::CXmlDataManager():
    iteratorRouteEvents(vectorRouteEvents)
{

}

CIterator<CRouteEvent>& CXmlDataManager::getRouteEvents()
{
    return iteratorRouteEvents;
}

bool CXmlDataManager::prepareRouteEvents(const QString &filePath) const
{

    shared_ptr<IXmlComponent> sptrRootComponent = CXmlReader::read(filePath);







    return true;
}

CXmlDataManager::~CXmlDataManager()
{
    delete vectorRouteEvents;
}

