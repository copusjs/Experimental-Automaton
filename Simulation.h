/*
Author: John Copus
Creation Date: October 21, 2016
Program Name: Automaton - Summation of all neighbors, Mod 10
File Name: Simulation.h
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
using namespace std;
#include "Load Screen.h"
#include "Matrix.h"

class Simulation
{
	private:
		int Iteration_Count;									//Stores the amount of iterations that the simulation runs. Customizable.
		Matrix M;
		LoadScreen Load;
	public:
		Simulation();											//Sets the cells of the Matrix to specified, hard-coded initial values
		~Simulation();
		void Run();												//Executes multiple Prints and Iterates; called in main.cpp
		int Prompt();											//Prompts the user for their choice of print function to be executed. Called within Run().
		void Change_Iteration_Count();							//Accepts a user input to change the length of the iteration loop in Run().
};

#endif