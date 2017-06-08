#pragma once
#include "Trainee.h"


class Batter : public Trainee
{
public:
	int power = 20;
	int movement = 5;

	Batter(std::string name);
	~Batter();

	std::string getTaunt() { return "I'm shooting for the moon!\n"; }
};

