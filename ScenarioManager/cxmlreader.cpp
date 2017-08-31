#include "cxmlreader.h"

CXmlReader::CXmlReader(const QString &path) : xmlFile(path)
                                             ,componentTree(Nfsm::ROOT_COMPONENT)
{

}

const CXmlCompositeComp& CXmlReader::getCompTreeFromXmlFile() const
{

    const IXmlComp *ptrCurrentComp = &componentTree;
    const IXmlComp *ptrParentComp;

    //QFile file(pathToXmlFile);

    //check is file open
    if(xmlFile.open(QIODevice::ReadOnly |QIODevice::Text)) // check
    {
        qDebug() <<QTime::currentTime().toString()<< "Start reading xml file";

        while(!xmlFile.atEnd())
        {
            QString str = xmlFile.readLine();
            QString openTag;
            QString value;
            QString closeTag;

            QRegExp openRx("<([^>]+)>");
            int pos = 0;

                //skip empty line and first xml line
            if(str.trimmed() == "" || str.trimmed()[1] == '?')
            {
                continue;
            } // code style

            while ((pos = openRx.indexIn(str, pos)) != -1)
            {
                openTag = openRx.cap(1).trimmed();
                QString closeTag(QString("([^<]*)</%1>").arg(openTag));
                QRegExp closeRx(closeTag);
                pos += openRx.matchedLength();
                int closePos = 0;

                if ((closePos = closeRx.indexIn(str, pos)) != -1)
                {
                    value = closeRx.cap(1).trimmed();
                    pos = closePos + closeRx.matchedLength();
                }
            }

                //removing close tag mark ('/')
            if(openTag[0] == '/')
            {
                openTag[0] = ' ';
                closeTag = openTag.trimmed();
                openTag = "";
            }


            //create composite component and pull in
            if(openTag != "" && value == "" && closeTag == "")
            {
                ptrCurrentComp->addComp(new CXmlCompositeComp(openTag));
                ptrParentComp = ptrCurrentComp;
                ptrCurrentComp = ptrParentComp->getVectorChilds().last();
            }

            //create primitive component
            else if(openTag != "" && value != "" && closeTag == "")
            {

                ptrCurrentComp->addComp(new CXmlPrimitiveComp(openTag, value));
            }

            // out from composite component
            else if(openTag == "" && value == "" && closeTag != "")
            {
                ptrCurrentComp = ptrParentComp;

            }
        }
            qDebug() <<QTime::currentTime().toString()<< "Done reading xml file";

    }
    else
    {
        qDebug() <<QTime::currentTime().toString()<< "Can't read xml file";
    }

    return componentTree;
}

CXmlReader::~CXmlReader()
{
    //???
}
