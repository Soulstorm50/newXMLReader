#include<iostream>

#include"ixmlcomponent.h"
#include"cxmlcompositecomponent.h"
#include"cxmlprimitivecomponent.h"

#include "cxmlreader.h"

#include"nfsm.h"

#include"cxmlreader.h"

#include<QDebug>

using namespace std;

int main()
{




    shared_ptr<IXmlComponent> comp = CXmlReader::read(Nfsm::XML_SCENARIO);

   qDebug() << comp.get()->getName();


shared_ptr<IXmlComponent> test(new CXmlCompositeComponent(ROOT_COMPONENT));

qDebug() << test.get()->getName();

shared_ptr<IXmlComponent> leaf(new CXmlPrimitiveComponent("Leaf", "Leaf Value"));

test.get()->add(leaf);


qDebug() << test.get()->getVectorChilds().last().get()->getName();

comp = test.get()->getVectorChilds().last();

qDebug() << comp.get()->getName();









//    CXmlCompositeComp root("Root");

//    IXmlComp * comp = new CXmlPrimitiveComp("First", "1");

//    root.addComp(comp);
//    root.addComp(new CXmlPrimitiveComp("Second", "2"));
//    root.addComp(new CXmlPrimitiveComp("Third", "3"));
//    root.addComp(new CXmlPrimitiveComp("Fourth", "4"));

//    qDebug() << "Size root - " << root.getVectorChilds().size() << endl;

//    qDebug() << "Root component Name: " << root.getName() << "Value: " << root.getValue() << endl;

//    qDebug() << root.getVectorChilds().at(0)->getName();

//    root.removeComp(comp);

//    qDebug() << root.getVectorChilds().at(0)->getName();


//    CXmlReader reader(Nfsm::XML_SCENARIO);

//    qDebug() << reader.getCompTreeFromXmlFile().getName();





}
