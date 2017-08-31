#include "cxmlprimitivecomponent.h"

CXmlPrimitiveComponent::CXmlPrimitiveComponent(const QString &name, const QString &value):
    componentName(name)
   ,componentValue(value)
{

}

void CXmlPrimitiveComponent::add(shared_ptr<IXmlComponent> component)
{
    qDebug() <<QTime::currentTime().toString()<< "Trying add element in prim comp!";
    //add exception
}

void CXmlPrimitiveComponent::remove(shared_ptr<IXmlComponent> component)
{
    qDebug() <<QTime::currentTime().toString()<< "Trying remove element in prim comp!";
    //add exception
}

const QVector<shared_ptr<IXmlComponent> > CXmlPrimitiveComponent::getVectorChilds() const
{
    //add exception
}

const QString &CXmlPrimitiveComponent::getName() const
{
    return componentName;
}

const QString &CXmlPrimitiveComponent::getValue() const
{
    return componentValue;
}

CXmlPrimitiveComponent::~CXmlPrimitiveComponent()
{

}
