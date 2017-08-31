#ifndef IXMLCOMP_H
#define IXMLCOMP_H

#include<vector>
#include<QString>
#include<QVector>

class IXmlComp
{
public:

    virtual void addComp (IXmlComp* component) = 0;
    virtual void removeComp(IXmlComp* component) = 0;
    virtual const QVector<IXmlComp*> getVectorChilds() const = 0;
    virtual const QString& getName() const = 0;
    virtual const QString& getValue() const = 0;

    virtual ~IXmlComp() = 0;
};

#endif // IXMLCOMP_H
