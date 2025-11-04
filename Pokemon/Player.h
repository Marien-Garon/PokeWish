#pragma once
#include "Entity.h"
#include "Utils.h"
#include "PokemonManager.h"
#include <vector>


class Player : Entity
{
public:
	
	//std::vector<int> inventory;

	std::vector<Pokemon> equip;

	void AddPokemonByName(std::string name);

	void AddPokemonByID(int id);

	void AddPokemon(std::initializer_list<Pokemon> pokeList);

	void DysplayEquip();
};

