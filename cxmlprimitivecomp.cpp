#include "cxmlprimitivecomp.h"

CXmlPrimitiveComp::CXmlPrimitiveComp(const QString name, const QString value)
{
    m_primCompName = name;
    m_primCompValue = value;
}

CXmlPrimitiveComp::~CXmlPrimitiveComp()
{

}


CXmlCompositeComp *CXmlPrimitiveComp::GetComposite()
{
    return NULL;
}

void CXmlPrimitiveComp::Add(IXmlComp *component)
{
    qDebug() <<QTime::currentTime().toString()<< "Trying add element in prim comp!";
}

void CXmlPrimitiveComp::Remove(IXmlComp *component)
{
    qDebug() <<QTime::currentTime().toString()<< "Trying remove element in prim comp!";
}

IXmlComp *CXmlPrimitiveComp::GetChild(int index)
{
    return NULL;
}

IXmlComp *CXmlPrimitiveComp::GetLastChild()
{
    return NULL;
}

QString CXmlPrimitiveComp::getName()
{
    return m_primCompName;
}

QString CXmlPrimitiveComp::getValue()
{
    return m_primCompValue;
}

int CXmlPrimitiveComp::getSize()
{
    return 0;
}
