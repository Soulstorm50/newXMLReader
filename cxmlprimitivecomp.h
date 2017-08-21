#ifndef CXMLPRIMITIVECOMP_H
#define CXMLPRIMITIVECOMP_H

#include "ixmlcomp.h"

#include "QString"
#include <QDebug>
#include <QTime>

class CXmlPrimitiveComp : public IXmlComp
{
public:
    CXmlPrimitiveComp(const QString name = "", const QString value = "");

    ~CXmlPrimitiveComp();

    // IXmlComp interface
public:
    virtual CXmlCompositeComp *GetComposite();
    virtual void Add(IXmlComp *component);
    virtual void Remove(IXmlComp *component);
    virtual IXmlComp *GetChild(int index);
    virtual IXmlComp *GetLastChild();
    virtual QString getName();
    virtual QString getValue();
    virtual int getSize();

private:

    QString m_primCompName;
    QString m_primCompValue;
};

#endif // CXMLPRIMITIVECOMP_H
