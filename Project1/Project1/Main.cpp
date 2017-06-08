/* 
	Author: Ryan Sorice
	CIS 17A - Final Project
	Lane Game
*/

//System libraries
#include <iostream>
#include <string>
#include <memory>

//User Libraries
#include "Trainee.h"
#include "Fielder.h"
#include "Batter.h"
#include "Team.h"

using namespace std;

//Function Prototypes
void AddPlayers(const shared_ptr<Team>);

int main() 
{
	//Intro + Create team name
	cout << "Welcome to /a/ Baseball-like game! \n" << "First, what will be your team's name? ";
	string tName;
	getline(cin, tName);
	auto team = make_shared<Team>(tName);
	system("cls");

	cout << "Your team has a total of 6 players; (the ideal being 3 batters and 3 fielders).\n" << "How many are batters? (The rest will be fielders) ";
	
	//ADD BATTERS TO TEAM
	int b;
	cin >> b;
	system("cls");
	b = b + 1;
	switch (b)
	{
		case 6:
		{
			cout << "Batter's name? ";
			string name;
			getline(cin, name);
			auto playerPtr = make_shared<Batter>(name);
			team->AddPlayer(playerPtr);
			system("cls");
		}
		case 5: 
		{
			cout << "Batter's name? ";
			string name;
			getline(cin, name);
			auto playerPtr = make_shared<Batter>(name);
			team->AddPlayer(playerPtr);
			system("cls");
		}
		case 4: 
		{
			cout << "Batter's name? ";
			string name;
			getline(cin, name);
			auto playerPtr = make_shared<Batter>(name);
			team->AddPlayer(playerPtr);
			system("cls");
		}
		case 3: 
		{
			cout << "Batter's name? ";
			string name;
			getline(cin, name);
			auto playerPtr = make_shared<Batter>(name);
			team->AddPlayer(playerPtr);
			system("cls");

		}
		case 2: 
		{
			cout << "Batter's name? ";
			string name;
			getline(cin, name);
			auto playerPtr = make_shared<Batter>(name);
			team->AddPlayer(playerPtr);
			system("cls");
		}
		case 1: 
		{
			cout << "Batter's name? ";
			string name;
			getline(cin, name);
			auto playerPtr = make_shared<Batter>(name);
			team->AddPlayer(playerPtr);
			system("cls"); break;
		}
		default: break;
	}

	//ADD FIELDERS TO TEAM
	b = b - 1;
	int f = 6 - b;
	while ( f != 0 )
	{
		cout << "Fielder's name? ";
		string name;
		getline(cin, name);
		auto playerPtr = make_shared<Fielder>(name);
		team->AddPlayer(playerPtr);
		system("cls");
		f--;
	}

	return 0;
}

void AddPlayers(const shared_ptr<Team> team)
{

}