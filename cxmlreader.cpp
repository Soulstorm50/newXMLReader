#include "cxmlreader.h"

CXmlReader::CXmlReader()
{

}

CXmlReader::~CXmlReader()
{

}


CXmlCompositeComp CXmlReader::getCompositeCompFromXmlFile(const QString path)
{
    CXmlCompositeComp xmlCompComp;

    IXmlComp *ptrCurrentComp = &xmlCompComp;

    IXmlComp *ptrParentComp;

    QFile file(path);

    //check is file open
    if(file.open(QIODevice::ReadOnly |QIODevice::Text)) // check
    {
        qDebug() <<QTime::currentTime().toString()<< "Start reading xml file";

        while(!file.atEnd())
        {
            QString str = file.readLine();
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
                ptrCurrentComp->Add(new CXmlCompositeComp(openTag));
                ptrParentComp = ptrCurrentComp;
                ptrCurrentComp = ptrParentComp->GetLastChild();
            }

            //create primitive component
            else if(openTag != "" && value != "" && closeTag == "")
            {

                ptrCurrentComp->Add(new CXmlPrimitiveComp(openTag, value));
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

    return xmlCompComp;
}
