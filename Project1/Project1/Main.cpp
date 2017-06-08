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
void AddBatters(const shared_ptr<Team>);
void AddFielders(const shared_ptr<Team>);

int main() 
{
	//Intro + Create team name
	cout << "Welcome to /a/ Baseball-like game! \n" << "First, what will be your team's name? ";
	string tName;
	getline(cin, tName);
	auto team = make_shared<Team>(tName);
	system("cls");

	cout << "Your team has a total of 6 players; (the ideal being 3 batters and 3 fielders).\n" << "How many are batters? (The rest will be fielders) ";
	system("pause");
	
	//ADD BATTERS TO TEAM
	int b;
	cin >> b;
	system("cls");
	b = b + 1;
	switch (b)
	{
		case 6: AddBatters(team);
		case 5: AddBatters(team);
		case 4: AddBatters(team);
		case 3: AddBatters(team);
		case 2: AddBatters(team);
		case 1: AddBatters(team);
		default: break;
	}

	//ADD FIELDERS TO TEAM
	b = b - 1;
	int f = 6 - b;
	int f1 = f;
	while ( f != 0 )
	{
		AddFielders(team);
		f--;
	}

	//Run the game
	int gameOver = 0;
	while (gameOver != 1)
	{
		cout << "1) View Team\n2) Play Game\n3) Match History\n4) Quit Game\n";
		int n = -1;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			system("cls");
			cout << "Team Name: " << team->getName() << endl << endl;
			cout << "Team Motto: " << team->getMotto() << endl << endl;
			cout << "Your team has " << b << " Batter(s) and " << f1 << " Fielder(s).\n";
			cout<< "Roster: " << team->ViewPlayers() << endl;
			break;
		}
		case 2:
		case 3:
		case 4:
		{
			system("cls");
			cout << "Goodbye!\n";
			system("pause");
			gameOver = 1; break;
		}
		default: "Invalid entry!\n"; break;
		}
	}

	return 0;
}

//Add Batters to team function
void AddBatters(const shared_ptr<Team> team)
{
	cout << "Batter's name? ";
	string name;
	getline(cin, name);
	auto playerPtr = make_shared<Batter>(name);
	team->AddPlayer(playerPtr);
	system("cls");
}

//Add Fielders to team function
void AddFielders(const shared_ptr<Team> team)
{
	cout << "Fielder's name? ";
	string name;
	getline(cin, name);
	auto playerPtr = make_shared<Fielder>(name);
	team->AddPlayer(playerPtr);
	system("cls");
}