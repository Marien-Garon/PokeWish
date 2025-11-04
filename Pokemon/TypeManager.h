#pragma once
#include "Type.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


class TypeManager
{
public:
	std::vector<Type> TypeList;

	Type* SearchTypeByName(std::string name);

	void InitType();
};

