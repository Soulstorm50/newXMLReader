#ifndef SEVENTDATA_H
#define SEVENTDATA_H

#include <QtCore>
#include <Nfsm.h>

using namespace Nfsm;

class SEventData
{
public:
    SEventData();

    qint32 m_indicatorID;
    qint32 m_indicatorValue;
};

#endif // SEVENTDATA_H
