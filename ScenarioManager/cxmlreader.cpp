#include "cxmlreader.h"

const shared_ptr<IXmlComponent> CXmlReader::CXmlReader::read(const QString &filePath)
{
    QFile xmlFile(filePath);

    xmlFile.open(QIODevice::ReadOnly |QIODevice::Text);

    shared_ptr<IXmlComponent> sptrComponentTree(new CXmlCompositeComponent(ROOT_COMPONENT));
    shared_ptr<IXmlComponent> sptrParentComp = sptrComponentTree;

    QString str;
    QString openTag;
    QString value;
    QString closeTagText;

    qDebug() <<QTime::currentTime().toString()<< "Start reading xml file";

    while(!xmlFile.atEnd())
    {
        str = xmlFile.readLine();
        QString closeTag;
        int pos = INDEX_0;

        while ((pos = OPEN_TAG_REGEXP.indexIn(str, pos)) != INDEX_NEGATIVE)
        {
            openTag = OPEN_TAG_REGEXP.cap(INDEX_1).trimmed();
            closeTagText = CLOSE_TAG_REGEXP_STR.arg(openTag);
            QRegExp closeRx(closeTagText);
            pos += OPEN_TAG_REGEXP.matchedLength();
            int closePos = INDEX_0;

            if ((closePos = closeRx.indexIn(str, pos)) != INDEX_NEGATIVE)
            {
                value = closeRx.cap(INDEX_1).trimmed();
                pos = closePos + closeRx.matchedLength();
            }
        }

        //removing close tag mark ('/')
        if(openTag[INDEX_0] == CHARACTER_SLASH)
        {
            openTag.remove(INDEX_0);
            closeTag = openTag;
            openTag = EMPTY_STRING;
        }

        if(openTag[INDEX_0] == CHARACTER_QUESTION)
        {
            qDebug() <<QTime::currentTime().toString()<< "YES its XML!!!!!!!!!!";
        }

        //create composite component and pull in
        else if(!(openTag.isEmpty()) && value.isEmpty() && closeTag.isEmpty())
        {
            sptrComponentTree.get()->add(shared_ptr<IXmlComponent>(new CXmlCompositeComponent(openTag)));
            sptrParentComp = sptrComponentTree;
            sptrComponentTree = sptrParentComp.get()->getVectorChilds().last();
        }

        //create primitive component
        else if(!(openTag.isEmpty()) && !(value.isEmpty()) && closeTag.isEmpty())
        {
            sptrComponentTree.get()->add(shared_ptr<IXmlComponent>(new CXmlPrimitiveComponent(openTag, value)));
        }

        // out from composite component
        else if(openTag.isEmpty() && value.isEmpty() && !(closeTag.isEmpty()))
        {
            sptrComponentTree = sptrParentComp;
        }
    }

    qDebug() <<QTime::currentTime().toString()<< "Done reading xml file";

    xmlFile.close();

    return sptrComponentTree;

}


CXmlReader::CXmlReader::~CXmlReader()
{

}
