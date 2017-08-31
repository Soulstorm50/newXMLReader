#ifndef IXMLCOMPONENT_H
#define IXMLCOMPONENT_H

#include <QString>
#include <QVector>
#include <memory>
#include <QDebug>
#include <QTime>

using std::shared_ptr;

class IXmlComponent
{
public:

    virtual void add (shared_ptr<IXmlComponent> component) = 0;
    virtual void remove(shared_ptr<IXmlComponent> component) = 0;
    virtual const QVector<shared_ptr<IXmlComponent>> getVectorChilds() const = 0;
    virtual const QString& getName() const = 0;
    virtual const QString& getValue() const = 0;

    virtual ~IXmlComponent() = 0;
};

#endif // IXMLCOMPONENT_H
