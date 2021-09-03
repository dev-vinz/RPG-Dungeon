#include "..\include\iobject.h"

IObject::IObject(int _power)
{
    this->power = _power;
}

QString IObject::show()
{
    return QString("%1 (%2)").arg(this->getName(), QString::number(this->getFeature()));
}

IObject::~IObject()
{
}
