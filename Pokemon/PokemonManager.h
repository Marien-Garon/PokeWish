#pragma once
#include "Pokemon.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;



class PokemonManager
{
public:
	std::vector<Pokemon> allPokemon;

	void InitialisePokemon();

	Pokemon SearchPokemonByName(std::string pokeName);

	Pokemon SearchPokemonByType(int id);

};

