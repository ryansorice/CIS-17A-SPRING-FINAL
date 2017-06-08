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
	std::vector<std::string> _history;

public:
	Team(std::string name);
	~Team();

	std::string getName() { return _name; }
	std::string getMotto() { return "Go HARD or go HOME!"; }

	void AddPlayer(std::shared_ptr<Trainee> _players);
	std::string ViewPlayers();
	std::vector<std::shared_ptr<Trainee>> PlayerBatting();
	std::string MatchHistory();
	void AddVictory(std::string history);
	void AddDefeat(std::string history);
};

