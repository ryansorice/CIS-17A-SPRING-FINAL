/* 
	Author: Ryan Sorice
	CIS 17A - Final Project
	Lane Game
*/

//System libraries
#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include <cstdlib>

//User Libraries
#include "Trainee.h"
#include "Fielder.h"
#include "Batter.h"
#include "Team.h"

using namespace std;

//Function Prototypes
void AddBatters(const shared_ptr<Team>);
void AddFielders(const shared_ptr<Team>);
void PlayBall(const shared_ptr<Team>, int &);
void Batting(const shared_ptr<Team>, int &, int &);

int main() 
{
	//random number seed
	srand(static_cast<unsigned int>(time(0)));

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
		case 6: AddBatters(team);
		case 5: AddBatters(team);
		case 4: AddBatters(team);
		case 3: AddBatters(team);
		case 2: AddBatters(team);
		case 1: AddBatters(team); break;
		default: cout << "Invalid entry!\n";  break;
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
	while (gameOver != 1 && gameOver != 2)
	{
		cout << "1) View Team\n2) Play Game\n3) Match History\n4) Quit Game\n";
		int n = -1, level=1;
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
			system("pause"); system("cls");
			break;
		}
		case 2:
		{
			PlayBall(team,level);
			break;
		}
		case 3: 
		{
			break;
		}
		case 4:
		{
			//Game over with a Quit; No victory
			system("cls");
			cout << "Goodbye!\n";
			system("pause");
			gameOver = 1; break;
		}
		default: "Invalid entry!\n"; break;
		}
		//Game over with a Victory
		if (level==6) gameOver = 2;
		
	}
	//Victory screen
	if (gameOver == 2) cout << "Congratulations! Your team" << team->getName() << " are the champions!\n";
	
	return 0;
}

//How to score and win the individual game
void Batting(const shared_ptr<Team> team, int &score, int &score1)
{
	int out = 0;
	while (out != 3) 
	{
		int strike = 0, ball = 0;
		//The at bat
		while (strike < 3 && ball < 4)
		{
			cout << "Here's the pitch...\n";
			int hit = rand() % 6 + 1;
			if (hit > 5)
			{
				cout << "Hit and SCORE!!!\n";
				score++;
				system("pause"); system("cls");
				break;
			}
			else if (hit > 3 && hit < 6) 
			{
				ball++;
				cout << "BALL!!!\n" << "Count: " << to_string(ball) << " : " << to_string(strike) << endl;
				system("pause"); system("cls");
			}
			else 
			{
				strike++;
				cout << "STEE-RIKE!!!!\n" << "Count: " << to_string(ball) << " : " << to_string(strike) << endl;
				system("pause"); system("cls");
			}
		}

		if (strike == 3)
		{
			out++;
			cout << "3 and you're OUT!!!\n";
		}
		else if (ball == 4) 
		{
			score++;
			cout << "4 and SCORE!!!\n";
		}

		cout << "Score: " << to_string(score) << " - " << to_string(score1) << endl;
		cout << "Outs: " << to_string(out) << endl;
		system("pause");
	}
	
}

//Individual game + submenu
void PlayBall(const shared_ptr<Team> team, int &level)
{
	system("cls");
	//Coin toss
	int coin = 0,
		toss = rand() % 2 + 1;
	cout << "Coin Toss! (1 for heads, 2 for tails)\n";
	cin >> coin;

	bool goFirst = true;
	if (toss == 1)
	{
		cout << "Heads!\n";
		if (coin == 1) cout << "Your team bats first.\n";
		else 
		{
			cout << "Your team takes the field first.\n";
			goFirst = false;
		}
		system("pause");
	}
	else if (toss == 2)
	{
		cout << "Tails!\n";
		if (coin == 2) cout << "Your team bats first.\n";
		else 
		{
			cout << "Your team takes the field first.\n";
			goFirst = false;
		}
		system("pause");
	}

	//Game Menu
	int score = 0, score1 = 0;
	int x = 0;
	while (x != 1 && x != 2)
	{
		system("cls");
		cout << "1) Bat/Field\n2) The Score\n3) Surrender\n";
		int n = 0;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			if (goFirst == true)
			{
				Batting(team, score, score1);
				goFirst = false;
			}
			else 
			{
				Batting(team, score1, score);
				goFirst = true;
			}
			break;
		}
		case 2:
		{
			cout << "Score: " << to_string(score) << " - " << to_string(score1) << endl;
			system("pause"); system("cls");
			break;
		}
		case 3:
		{
			cout << "Game Over!\n";
			x = 1;
			system("pause");
		}
		default: break;
		}
		if (x == 2) level++;
	}
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