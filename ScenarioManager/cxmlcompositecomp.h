#ifndef CXMLCOMPOSITECOMP_H
#define CXMLCOMPOSITECOMP_H

#include"ixmlcomp.h"

class CXmlCompositeComp : public IXmlComp
{
public:
    explicit CXmlCompositeComp(const QString& name);

    virtual void addComp(IXmlComp *component) override;
    virtual void removeComp(IXmlComp *component) override;
    virtual const QVector<IXmlComp *> getVectorChilds() const override;
    virtual const QString& getName() const override;
    virtual const QString& getValue() const override;

    virtual ~CXmlCompositeComp() override;


private:
    QString componentName;
    QString componentValue;
    QVector<IXmlComp*> vectorComponents;
};

#endif // CXMLCOMPOSITECOMP_H
