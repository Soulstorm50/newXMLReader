#include "cxmlcompositecomp.h"

CXmlCompositeComp::CXmlCompositeComp(const QString name, const QString value)
{
    m_compCompName = name;
    m_compCompValue = value;
}

CXmlCompositeComp::~CXmlCompositeComp()
{

}

CXmlCompositeComp *CXmlCompositeComp::GetComposite()
{
    return this;
}

void CXmlCompositeComp::Add(IXmlComp *component)
{
    qDebug() <<QTime::currentTime().toString()<< "Trying add element in comp comp!";
    vectComp.push_back(component);
}

void CXmlCompositeComp::Remove(IXmlComp *component)
{
    qDebug() <<QTime::currentTime().toString()<< "Trying remove element in comp comp!";
    for (auto it = vectComp.begin(); it != vectComp.end(); it++)
    {
        if (*it == component)
        {
            vectComp.erase(it);
            break;
        }
    }
}

IXmlComp *CXmlCompositeComp::GetChild(int index)
{
    std::vector<IXmlComp*>::iterator it = vectComp.begin() + index;
    return *it;
}

IXmlComp *CXmlCompositeComp::GetLastChild()
{
    std::vector<IXmlComp*>::iterator it = vectComp.end();
    return *it;
}

QString CXmlCompositeComp::getName()
{
    return m_compCompName;
}

QString CXmlCompositeComp::getValue()
{
    return m_compCompValue;
}

int CXmlCompositeComp::getSize()
{
    return vectComp.size();
}
