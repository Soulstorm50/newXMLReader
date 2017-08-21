#ifndef CXMLCOMPOSITECOMP_H
#define CXMLCOMPOSITECOMP_H

#include "ixmlcomp.h"

#include "QString"
#include <QDebug>
#include <QTime>

class CXmlCompositeComp : public IXmlComp
{
public:
    CXmlCompositeComp(const QString name = "", const QString value = "");

    ~CXmlCompositeComp();

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

    QString m_compCompName;
    QString m_compCompValue;
    std::vector<IXmlComp*> vectComp;
};

#endif // CXMLCOMPOSITECOMP_H
