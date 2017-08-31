#ifndef CXMLCOMPOSITECOMPONENT_H
#define CXMLCOMPOSITECOMPONENT_H

#include "ixmlcomponent.h"

class CXmlCompositeComponent : public IXmlComponent
{
public:
    explicit CXmlCompositeComponent(const QString& name);

    virtual void add(shared_ptr<IXmlComponent> component) override;
    virtual void remove(shared_ptr<IXmlComponent> component) override;
    virtual const QVector<shared_ptr<IXmlComponent>> getVectorChilds() const override;
    virtual const QString& getName() const override;
    virtual const QString& getValue() const override;

    virtual ~CXmlCompositeComponent() override;


private:
    QString componentName;
    QString componentValue;
    QVector<shared_ptr<IXmlComponent>> vectorComponents;
};

#endif // CXMLCOMPOSITECOMPONENT_H
