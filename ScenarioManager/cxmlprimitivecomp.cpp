#include "cxmlprimitivecomp.h"


CXmlPrimitiveComp::CXmlPrimitiveComp(const QString &name, const QString &value):componentName(name)
                                                                               ,componentValue(value)
{

}

void CXmlPrimitiveComp::addComp(IXmlComp *component)
{
    //add exception
}

void CXmlPrimitiveComp::removeComp(IXmlComp *component)
{
    //add exception
}

const QVector<IXmlComp *> CXmlPrimitiveComp::getVectorChilds() const
{
    //add exception
}

const QString& CXmlPrimitiveComp::getName() const
{
    return componentName;
}

const QString& CXmlPrimitiveComp::getValue() const
{
    return componentValue;
}

CXmlPrimitiveComp::~CXmlPrimitiveComp()
{

}
