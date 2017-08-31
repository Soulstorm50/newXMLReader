#ifndef CXMLPRIMITIVECOMPONENT_H
#define CXMLPRIMITIVECOMPONENT_H


#include "ixmlcomponent.h"

class CXmlPrimitiveComponent : public IXmlComponent
{
public:
    explicit CXmlPrimitiveComponent(const QString& name, const QString& value);

    virtual void add(shared_ptr<IXmlComponent> component) override;
    virtual void remove(shared_ptr<IXmlComponent> component) override;
    virtual const QVector<shared_ptr<IXmlComponent>> getVectorChilds() const override;
    virtual const QString& getName() const override;
    virtual const QString& getValue() const override;

    virtual ~CXmlPrimitiveComponent() override;

private:
    QString componentName;
    QString componentValue;
};

#endif // CXMLPRIMITIVECOMPONENT_H
