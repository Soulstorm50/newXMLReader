#include "cxmlcompositecomp.h"

CXmlCompositeComp::CXmlCompositeComp(const QString &name):componentName(name)
                                                         ,componentValue("")
{
}

void CXmlCompositeComp::addComp(IXmlComp *component)
{
    vectorComponents.push_back(component);
}

void CXmlCompositeComp::removeComp(IXmlComp *component)
{
    for (auto it = vectorComponents.begin(); it != vectorComponents.end(); it++)
    {
        if (*it == component)
        {
            vectorComponents.erase(it);
            break;
        }
    }
}

const QVector<IXmlComp *> CXmlCompositeComp::getVectorChilds() const
{
    return vectorComponents;
}

const QString& CXmlCompositeComp::getName() const
{
    return componentName;
}

const QString& CXmlCompositeComp::getValue() const
{
    return componentValue;
    //add exception
}

CXmlCompositeComp::~CXmlCompositeComp()
{
    for(auto component : vectorComponents)
    {
        delete component;
        component = 0;
    }
}
