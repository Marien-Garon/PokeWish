#include "PokemonManager.h"

void PokemonManager::InitialisePokemon()
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
		p.id = entry.value("id", 0);
		p.name = entry.value("nom", "inconnu");
		/*p.types = entry.value("types", std::vector<std::string>{});
		p.talents = entry.value("talents", std::vector<std::string>{});*/

		auto stats = entry["stats"];
		p.hp = stats.value("hp", 0);
		p.atk = stats.value("attack", 0);
		p.def = stats.value("defense", 0);
		p.atkspe = stats.value("special-attack", 0);
		p.defspe = stats.value("special-defense", 0);
		p.speed = stats.value("speed", 0);

		/*p.attaques = entry.value("attaques", std::vector<std::string>{});*/
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