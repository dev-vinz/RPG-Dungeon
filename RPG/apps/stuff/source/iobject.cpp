#include "..\include\iobject.h"

IObject::IObject(int _power)
{
    this->power = _power;
}
void IObject::show()
{
    cout << this->getName() + "(" + to_string(this->getFeature()) + ")" << endl;
}

IObject::~IObject()
{

}
