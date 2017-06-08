#pragma once
#include "Trainee.h"


class Fielder : public Trainee
{
public:
	int power = 5;
	int movement = 20;

	Fielder(std::string name);
	~Fielder();

	std::string getTaunt() { return "Swing Batter, Swing!\n"; }
};

