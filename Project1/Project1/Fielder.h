#pragma once
#include "Trainee.h"


class Fielder : public Trainee
{
private:

	int _power = 5;
	int _movement = 20;
public:

	Fielder(std::string name);
	~Fielder();

	std::string getTaunt() { return "Swing Batter, Swing!\n"; }
};

