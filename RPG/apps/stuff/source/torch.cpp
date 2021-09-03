#include "..\include\torch.h"

Torch::Torch(int _power) : IObject(_power)
{
}

QString Torch::show()
{
    return this->getName();
}

void Torch::use(Character *)
{
}
