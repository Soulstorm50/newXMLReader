#include "ixmlcomp.h"
#include "cxmlprimitivecomp.h"
#include "cxmlcompositecomp.h"
#include "cscenariomanager.h"

#include "ixmlreader.h"
#include "cxmlreader.h"

#include <regex>
#include <iostream>
#include <string>
#include <fstream>

#include <QString>
#include <QRegExp>
#include <QFile>
#include <QDebug>

int main()
{


    CScenarioManager manager;

    qDebug() << manager.prepareScenario();










     //CXmlReader reader;
    //CXmlCompositeComp xmlCompComp = reader.getCompositeCompFromXmlFile("D:\\111\\odstudents\\newXMLReader\\xml\\test3.xml");















//CXmlCompositeComp * collection = new CXmlCompositeComp("MainCollection", "Some Value");

//IXmlComp * comp;

//qDebug() << collection->getName();
//qDebug() << collection->getValue();
//collection->Add(new CXmlPrimitiveComp("Prim1", "Prim1 value"));
//collection->Add(new CXmlPrimitiveComp("Prim2", "Prim2 value"));
//collection->Add(new CXmlPrimitiveComp("Prim3", "Prim3 value"));
//collection->Add(new CXmlPrimitiveComp("Prim4", "Prim4 value"));
//collection->Add(new CXmlCompositeComp("CompComp1", "CC1Value"));


//for(int i = 0; i < collection->getSize(); i++)
//{
//    if(collection->GetChild(i)->GetComposite() == NULL) {
//    qDebug() << collection->GetChild(i)->getName();
//    } else {
//        comp = collection->GetChild(i);
//        qDebug() << comp->getName();

//    }
//}








    return 0;
}
