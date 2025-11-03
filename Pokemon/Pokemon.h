#pragma once
#include "Entity.h"
#include "iostream"
#include "Utils.h"
#include "TypeManager.h"

class Pokemon : public Entity
{
public:
	int id;

	int hp;
	//int maxhp;
	int atk;
	int def;
	int atkspe;
	int defspe;
	int speed;

	bool canEvolve;
	int evolutionID;

	std::vector<Type*> type;

	void DysplayStat();

};

