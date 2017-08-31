#ifndef CXMLREADER_H
#define CXMLREADER_H

#include "cxmlcompositecomponent.h"
#include "cxmlprimitivecomponent.h"
#include "ixmlcomponent.h"
#include "nfsm.h"
#include <memory>
#include <QFile>
#include <QString>
#include <QRegExp>
#include <QDebug>
#include <QTime>

using namespace Nfsm;

class CXmlReader
{

public:

    static const shared_ptr<IXmlComponent> read(const QString& filePath);

private:

    CXmlReader() = delete;
    CXmlReader(const CXmlReader&) = delete;
    CXmlReader& operator=( const CXmlReader& ) = delete;

    ~CXmlReader();

};

#endif // CXMLREADER_H
