#pragma once
#include <vector>
#include <string>

class Type
{
public:
	
	std::string name;

	std::vector<Type*> weakness;
	std::vector<Type*> resistance;

	bool isResisted(Type atkType);

	bool isWeak(Type atkType);
};
