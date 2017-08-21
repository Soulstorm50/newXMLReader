#ifndef IXMLCOMP_H
#define IXMLCOMP_H

#include <QString>

class CXmlCompositeComp;
class CXmlPrimitiveComp;

class IXmlComp
{
public:

    IXmlComp();

    virtual ~IXmlComp();

    virtual CXmlCompositeComp* GetComposite() = 0;
    //virtual void Operation () = 0;
    virtual void Add (IXmlComp* component) = 0;
    virtual void Remove(IXmlComp* component) = 0;
    virtual IXmlComp* GetChild(int index) = 0;
    virtual IXmlComp* GetLastChild() = 0;
    virtual QString getName() = 0;
    virtual QString getValue() = 0;
    virtual int getSize() = 0;




};
#endif // IXMLCOMP_H
