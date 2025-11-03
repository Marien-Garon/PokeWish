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

	void InitialisePokemon(TypeManager* tm);

	Pokemon SearchPokemonByName(std::string pokeName);

	Pokemon SearchPokemonByID(int id);
};

