#ifndef IXMLREADER_H
#define IXMLREADER_H

#include"cxmlcompositecomp.h"
#include"cxmlprimitivecomp.h"
#include"nfsm.h"


class IXmlReader
{
public:

    virtual const CXmlCompositeComp& getCompTreeFromXmlFile() const = 0;

    virtual ~IXmlReader() = 0;
};

#endif // IXMLREADER_H
