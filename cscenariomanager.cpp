#include "cscenariomanager.h"

CScenarioManager::CScenarioManager() : m_iterator(m_routeEventCollection)
{

}

CScenarioManager::~CScenarioManager()
{

}


CIterator<CRouteEvent> &CScenarioManager::getEventIterator()
{
    return m_iterator;
}

bool CScenarioManager::prepareScenario() const
{

    // in progress

    bool result = true;

    CXmlCompositeComp* mainComponent;

    CXmlReader* xmlReader = new CXmlReader();

    mainComponent = xmlReader->getCompositeCompFromXmlFile(xmlScenario).GetComposite();



    if(mainComponent->getSize() == 0)
    {
        result = false;
    }


   //initEvents(mainComponent);



    return result;
}

void CScenarioManager::initEvents(IXmlComp* component)
{

    SEventData indicator;
    CRouteEvent event;

    for(int i = 0; i < component->getSize(); i++)
    {
        if(component->GetChild(i)->getName() != EVENT_COMPOSITE)
        {
            initEvents(component->GetChild(i));
        }
        else
        {
            if(component->GetChild(i)->getName() == TIME_COMPONENT)
            {
                event.setEventTime((qint32)component->GetChild(i)->getValue().toInt());
            }
            else
            {
            indicator.m_indicatorID = (qint32)component->GetChild(i)->getName().toInt();
            indicator.m_indicatorValue = (qint32)component->GetChild(i)->getValue().toInt();
            event.addEventData(indicator);
            }
        }
    }

    m_routeEventCollection.push_back(event);
}
