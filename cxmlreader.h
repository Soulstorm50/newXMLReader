#ifndef CXMLREADER_H
#define CXMLREADER_H

#include "ixmlreader.h"
#include "cxmlcompositecomp.h"
#include "nfsm.h"


#include <QFile>
#include <QString>
#include <QRegExp>
#include <QDebug>
#include <QTime>

#include <fstream>

class CXmlReader : public IXmlReader
{
public:
    CXmlReader();

    ~CXmlReader();


    // IXmlReader interface
public:
    virtual CXmlCompositeComp getCompositeCompFromXmlFile(const QString path);
};

#endif // CXMLREADER_H
