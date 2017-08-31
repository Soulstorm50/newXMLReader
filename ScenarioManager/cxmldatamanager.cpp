#include "cxmldatamanager.h"

CXmlDataManager::CXmlDataManager(const QString& filePath):
    iteratorRouteEvents(vectorRouteEvents)
{
    prepareRouteEvents(filePath);
}

CIterator<CRouteEvent>& CXmlDataManager::getRouteEvents()
{
    return iteratorRouteEvents;
}

void CXmlDataManager::prepareRouteEvents(const QString &filePath)
{
    shared_ptr<IXmlComponent> sptrRootComponent = CXmlReader::read(filePath);

    buildRouteEventsFromComponents(sptrRootComponent);
}

bool CXmlDataManager::isReady() const
{
    return vectorRouteEvents.empty();
}

void CXmlDataManager::buildRouteEventsFromComponents(const shared_ptr<IXmlComponent> components)
{
    CRouteEvent event;
    SEventData data;

    for(shared_ptr<IXmlComponent> component : components.get()->getVectorChilds())
    {

        if(component.get()->getName() == TIME_COMPONENT && !component.get()->getValue().isEmpty())
        {
            //catch primitive component "time"
            event.setEventTime((qint32)component.get()->getValue().toInt());
        }

        else if(!component.get()->getName().isEmpty() && !component.get()->getValue().isEmpty())
        {
            //catch any primitive component
            data.m_indicatorID = (qint32)component.get()->getName().toInt();
            data.m_indicatorValue = (qint32)component.get()->getValue().toInt();
            event.addEventData(data);
        }

        else if(component.get()->getName() == EVENT_COMPOSITE)
        {
            //catch composite component "event"
            event.clear();
            buildRouteEventsFromComponents(component);
            vectorRouteEvents.push_back(event);
        }

        else if(component.get()->getValue().isEmpty())
        {
            //catch any composite component
            buildRouteEventsFromComponents(component);
        }
    }
}

CXmlDataManager::~CXmlDataManager()
{
    vectorRouteEvents.clear();
}

