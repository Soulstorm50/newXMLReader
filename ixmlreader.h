#ifndef IXMLREADER_H
#define IXMLREADER_H

#include "ixmlcomp.h"
#include "cxmlprimitivecomp.h"
#include "cxmlcompositecomp.h"

#include <QString>

class IXmlReader
{
public:
    IXmlReader();

    virtual ~IXmlReader();

    virtual CXmlCompositeComp getCompositeCompFromXmlFile(QString path) = 0;


};

#endif // IXMLREADER_H
