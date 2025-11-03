#pragma once
#include "Entity.h"
#include "iostream"
#include "Utils.h"

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

	void DysplayStat();

};

