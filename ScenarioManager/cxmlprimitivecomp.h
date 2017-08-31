#ifndef CXMLPRIMITIVECOMP_H
#define CXMLPRIMITIVECOMP_H

#include"ixmlcomp.h"

class CXmlPrimitiveComp : public IXmlComp
{
public:
    explicit CXmlPrimitiveComp(const QString& name, const QString& value);

    virtual void addComp(IXmlComp *component) override;
    virtual void removeComp(IXmlComp *component) override;
    virtual const QVector<IXmlComp *> getVectorChilds() const override;
    virtual const QString& getName() const override;
    virtual const QString& getValue() const override;

    virtual ~CXmlPrimitiveComp() override;

private:
    QString componentName;
    QString componentValue;
};

#endif // CXMLPRIMITIVECOMP_H
