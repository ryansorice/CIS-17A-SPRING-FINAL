#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Trainee.h"

class Team
{
private:
	std::string _name;
	std::vector<std::shared_ptr<Trainee>> players;

public:
	

	Team(std::string name);
	~Team();

	std::string getName() { return _name; }
	std::string getMotto() { return "Go HARD or go HOME!"; }

	void AddPlayer(std::shared_ptr<Trainee> _players);
	std::string ViewPlayers();

};

