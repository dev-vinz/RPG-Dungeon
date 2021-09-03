#include "..\include\iobject.h"

IObject::IObject(int _power)
{
    this->power = _power;
}

IObject::~IObject()
{
}

QString IObject::show() const
{
    return QString("%1 (%2)").arg(this->getName(), QString::number(this->getFeature()));
}
