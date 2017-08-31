#include "cxmlcompositecomponent.h"

CXmlCompositeComponent::CXmlCompositeComponent(const QString &name):
    componentName(name)
   ,componentValue("")
{

}

void CXmlCompositeComponent::add(shared_ptr<IXmlComponent> component)
{
    vectorComponents.push_back(component);
    qDebug() <<QTime::currentTime().toString()<< "Add element "
             << component.get()->getName() << "Value: "
             << component.get()->getValue() << " in "
             << this->getName();
}

void CXmlCompositeComponent::remove(shared_ptr<IXmlComponent> component)
{
    qDebug() <<QTime::currentTime().toString()<< "Trying remove element in comp comp!";
    for (auto it = vectorComponents.begin(); it != vectorComponents.end(); it++)
    {
        if (*it == component)
        {
            vectorComponents.erase(it);
            break;
        }
    }
}

const QVector<shared_ptr<IXmlComponent> > CXmlCompositeComponent::getVectorChilds() const
{
    return vectorComponents;
}

const QString &CXmlCompositeComponent::getName() const
{
    return componentName;
}

const QString &CXmlCompositeComponent::getValue() const
{
    return componentValue;
}

CXmlCompositeComponent::~CXmlCompositeComponent()
{

}
