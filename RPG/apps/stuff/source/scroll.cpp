#include "..\include\scroll.h"

Scroll::Scroll(int _power): IObject(_power)
{

}
void Scroll::use(Character *_character)
{
    _character->updateHealth(-this->getFeature());
}
