/*
Author: John Copus
Creation Date: October 21, 2016
Program Name: Automaton - Summation of all neighbors, Mod 10
File Name: Load Screen.cpp
*/

#include "Load Screen.h"
#include <Windows.h>
#include <iomanip>
#include <string>

//-----Constructor Definition-----

LoadScreen::LoadScreen()
{
	countdown = 5;
}

//-----Destructor Definition-----

LoadScreen::~LoadScreen()
{
}

//-----Change Countdown Definition-----

void LoadScreen::Change_countdown()
{
	string input;
	int input_int;
	do
	{
		cout << "\n\n\tThe countdown is the number of seconds that the loadscreen persists\n"
			<< "\tbefore the simulation begins. It can be anywhere from 0 to 5 seconds.";
		cout << "\n\n\tEnter a new countdown length: ";
		while(getline(cin, input) && input.empty())							//Checks if user typed anything before the enter key was pressed.
		{
			system("cls");
			cout << "\n\n\tYou typed nothing.";
			cout << "\n\n\tIf you don't want a countdown, type '0' when prompted.";
			Sleep(4000);
			system("cls");
			cout << "\n\n\tThe countdown is the number of seconds that the loadscreen persists\n"
				<< "\tbefore the simulation begins. It can be anywhere from 0 to 5 seconds.";
			cout << "\n\n\tEnter a new countdown length: ";
		}
		input_int = atoi(input.c_str());
		if(input_int > -1 && input_int < 6)
		{
			countdown = input_int;
			system("cls");
			cout << "\n\n\tThe new countdown time is " << countdown << " seconds.";
			Sleep(4000);
			system("cls");
		}
		else
		{
			system("cls");
			cout << "\n\n\tThe countdown time must be between 0 and 5 seconds.";
			Sleep(4000);
			system("cls");
		}
	}while(input_int > 5 || input_int < 0);
	return;
}

//-----Run Definition-----

void LoadScreen::Run()
{
	for(int i = countdown; i > 0; i--)
	{
		cout << "\n\n\t\tIt's recommended that you maximize this screen.";
		if(i == 5)
		{
			cout << "\n\n\n" << setw(45) << "==========";
			cout << "\n" << setw(36) << "||";
			cout << "\n" << setw(36) << "||";
			cout << "\n" << setw(36) << "||";
			cout << "\n" << setw(36) << "||";
			cout << "\n" << setw(43) << "========";
			cout << "\n" << setw(45) << "||";
			cout << "\n" << setw(45) << "||";
			cout << "\n" << setw(45) << "||";
			cout << "\n" << setw(45) << "||";
			cout << "\n" << setw(36) << "||" << setw(9) << "||";
			cout << "\n" << setw(36) << "||" << setw(9) << "||";
			cout << "\n" << setw(43) << "=======";
		}
		if(i == 4)
		{
			cout << "\n\n\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "//||";
			cout << "\n" << setw(43) << "// ||";
			cout << "\n" << setw(43) << "//  ||";
			cout << "\n" << setw(43) << "//   ||";
			cout << "\n" << setw(43) << "//    ||";
			cout << "\n" << setw(43) << "//     ||";
			cout << "\n" << setw(45) << "===========";
			cout << "\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "||";
		}
		if(i == 3)
		{
			cout << "\n\n\n" << setw(44) << "=======";
			cout << "\n" << setw(37) << "||" << setw(9) << "||";
			cout << "\n" << setw(37) << "||" << setw(9) << "||";
			cout << "\n" << setw(46) << "||";
			cout << "\n" << setw(46) << "||";
			cout << "\n" << setw(44) << "=====";
			cout << "\n" << setw(46) << "||";
			cout << "\n" << setw(46) << "||";
			cout << "\n" << setw(46) << "||";
			cout << "\n" << setw(46) << "||";
			cout << "\n" << setw(37) << "||" << setw(9) << "||";
			cout << "\n" << setw(37) << "||" << setw(9) << "||";
			cout << "\n" << setw(44) << "=======";
		}
		if(i == 2)
		{
			cout << "\n\n\n" << setw(44) << "=======";
			cout << "\n" << setw(37) << "||" << setw(9) << "||";
			cout << "\n" << setw(37) << "||" << setw(9) << "||";
			cout << "\n" << setw(46) << "||";
			cout << "\n" << setw(45) << "//";
			cout << "\n" << setw(43) << "/";
			cout << "\n" << setw(42) << "/";
			cout << "\n" << setw(41) << "/";
			cout << "\n" << setw(40) << "/";
			cout << "\n" << setw(39) << "/";
			cout << "\n" << setw(38) << "/";
			cout << "\n" << setw(37) << "||";
			cout << "\n" << setw(45) << "==========";
		}
		if(i == 1)								//Consider tacking on a print of '0' to the end of this one. Whatever looks good.
		{
			cout << "\n\n\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "//||";
			cout << "\n" << setw(43) << "// ||";
			cout << "\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "||";
			cout << "\n" << setw(43) << "||";
			cout << "\n" << setw(45) << "======";
		}
		Sleep(1000);
		system("cls");
	}
	return;
}