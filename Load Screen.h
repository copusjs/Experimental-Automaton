/*
Author: John Copus
Creation Date: October 21, 2016
Program Name: Automaton - Summation of all neighbors, Mod 10
File Name: Load Screen.h
*/

#ifndef LOADSCREEN_H
#define LOADSCREEN_H

#include <iostream>
using namespace std;

class LoadScreen
{
	private:
		int countdown;					//countdown is the number of seconds that the load screen persists before the simulation starts.
	public:
		LoadScreen();
		~LoadScreen();
		void Change_countdown();
		void Run();						//Runs the load screen
};

#endif