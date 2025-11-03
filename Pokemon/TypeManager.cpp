#include "TypeManager.h"


Type* TypeManager::SearchTypeByName(std::string nameType)
{
	for (auto& type : TypeList)
	{
		if (type->name == nameType)
			return type;
	}
	return nullptr;
}

void TypeManager::InitType()
{
	std::ifstream file("type.json");  //ça marche pas du tout lets gooooooo
	if (!file.is_open()) 
	{
		std::cerr << "erreur : impossible d'ouvrir le fichier" << std::endl;
		return;
	}

	json data;
	file >> data;
	file.close();

	for (auto& entry : data) 
	{
		Type t;
		t.name = entry.value("name", "none");
		TypeList.push_back(&t);
	}

	for (size_t i = 0; i < data.size(); ++i) {
		const auto& entry = data[i];
		Type* t = TypeList[i];

		for (const std::string& resName : entry["resistances"]) {
			if (Type* res = SearchTypeByName(resName))
				t->resistance.push_back(res);
		}

		for (const std::string& weakName : entry["faiblesses"]) {
			if (Type* weak = SearchTypeByName(weakName))
				t->weakness.push_back(weak);
		}
	}
}
