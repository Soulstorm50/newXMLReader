#ifndef CROUTEEVENT_H
#define CROUTEEVENT_H

#include <QtCore>
#include <vector>
#include <seventdata.h>
#include <citerator.h>

using std::vector;


class CRouteEvent
{
public:
    CRouteEvent();
    void addEventData(const SEventData& eventData);
    void setEventTime(const qint32& time);
    const qint32& getTimeEvent()const;
    CIterator<SEventData>& getIterator();
    ~CRouteEvent();

private:
    qint32 m_eventTime;
    vector<SEventData> m_dataIndicatorCollection;
    CIterator<SEventData> m_iterator;

};

inline void CRouteEvent::setEventTime(const qint32 &time)
{
    m_eventTime = time;
}

inline const qint32 &CRouteEvent::getTimeEvent() const
{
    return m_eventTime;
}

#endif // CROUTEEVENT_H
