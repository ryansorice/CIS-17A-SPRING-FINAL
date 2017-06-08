#pragma once
#include "Trainee.h"


class Batter : public Trainee
{
private:
	int _power = 20;
	int _movement = 5;

public:
	Batter(std::string name);
	~Batter();

	std::string getTaunt() { return "I'm shooting for the moon!\n"; }
};

