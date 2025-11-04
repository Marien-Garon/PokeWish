#include "PokemonManager.h"

void PokemonManager::InitialisePokemon(TypeManager* tm)
{
	std::ifstream file("pokedex_fr.json");  //ça marche pas du tout lets gooooooo
	if (!file.is_open()) {
		std::cerr << "erreur : impossible d'ouvrir le fichier" << std::endl;
		return;
	}

	json data;
	file >> data;
	file.close();

	for (auto& entry : data) {
		Pokemon p;
		std::vector<std::string> strType;
		p.id = entry.value("id", 0);
		p.name = entry.value("nom", "inconnu");
		strType = entry.value("types", std::vector<std::string>{});
		for (int i = 0; i < strType.size(); ++i)
		{
			p.type.push_back(tm->SearchTypeByName(strType[i]));
		}

		auto stats = entry["stats"];
		p.hp = stats.value("hp", 0);
		p.atk = stats.value("attack", 0);
		p.def = stats.value("defense", 0);
		p.atkspe = stats.value("special-attack", 0);
		p.defspe = stats.value("special-defense", 0);
		p.speed = stats.value("speed", 0);

		p.evolutionID = entry.value("evolution_suivante", -1);

		allPokemon.push_back(std::move(p));
	}
}

Pokemon PokemonManager::SearchPokemonByName(std::string pokeName)
{
	for (auto& poke : allPokemon)
	{
		if (pokeName == poke.name)
			return poke;
	}
}

Pokemon PokemonManager::SearchPokemonByID(int id)
{
	return allPokemon[id-1];
}