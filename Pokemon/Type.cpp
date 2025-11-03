#include "Type.h"

bool Type::isResisted(Type atkType)
{
	for (auto& type : resistance)
	{
		if (type->name == atkType.name)
			return true;
	}
	return false;
}

bool Type::isWeak(Type atkType)
{
	for (auto& type : weakness)
	{
		if (type->name == atkType.name)
			return true;
	}
	return false;
}