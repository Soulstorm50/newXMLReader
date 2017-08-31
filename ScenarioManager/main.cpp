#include<iostream>

#include"ixmlcomp.h"
#include"cxmlcompositecomp.h"
#include"cxmlprimitivecomp.h"

#include"nfsm.h"

#include"cxmlreader.h"

#include<QDebug>

using namespace std;

int main()
{


    CXmlCompositeComp root("Root");

    IXmlComp * comp = new CXmlPrimitiveComp("First", "1");

    root.addComp(comp);
    root.addComp(new CXmlPrimitiveComp("Second", "2"));
    root.addComp(new CXmlPrimitiveComp("Third", "3"));
    root.addComp(new CXmlPrimitiveComp("Fourth", "4"));

    qDebug() << "Size root - " << root.getVectorChilds().size() << endl;

    qDebug() << "Root component Name: " << root.getName() << "Value: " << root.getValue() << endl;

    qDebug() << root.getVectorChilds().at(0)->getName();

    root.removeComp(comp);

    qDebug() << root.getVectorChilds().at(0)->getName();


    CXmlReader reader(Nfsm::XML_SCENARIO);

    qDebug() << reader.getCompTreeFromXmlFile().getName();





}
