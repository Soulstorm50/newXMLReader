#include "crouteevent.h"

CRouteEvent::CRouteEvent() :
    m_iterator(m_dataIndicatorCollection)
{

}

void CRouteEvent::addEventData(const SEventData &eventData)
{
    m_dataIndicatorCollection.push_back(eventData);
}

CIterator<SEventData> &CRouteEvent::getIterator()
{
    return m_iterator;
}

CRouteEvent::~CRouteEvent()
{

}
