#ifndef CXMLREADER_H
#define CXMLREADER_H

#include"ixmlreader.h"

#include<QFile>
#include<QString>
#include<QRegExp>
#include<QDebug>
#include<QTime>

class CXmlReader : public IXmlReader
{
public:
    CXmlReader(const QString& path);

    virtual const CXmlCompositeComp& getCompTreeFromXmlFile() const override;

    virtual ~CXmlReader() override;

private:

    QString pathToXmlFile;
    QFile xmlFile;
    CXmlCompositeComp componentTree;
};

#endif // CXMLREADER_H
