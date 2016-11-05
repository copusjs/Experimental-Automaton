/*
Author: John Copus
Creation Date: October 21, 2016
Program Name: Automaton - Summation of all neighbors, Mod 10
File Name: main.cpp
Program Description:	
	Creates a 2-D grid of int values. For each cell in the grid, it calculates the sum of the values for the cell's 8 neighbors 
	(adding the cell's own value to the sum), and then calculates the remainder when that sum is divided by 10. This value is stored
	within a temporary grid, and will become that cell's new iterated value. Once the new values for every cell in the grid have been
	stored, these new values are copied into the original grid, completing an iteration. The results are printed (the user has a choice
	of how the grid is printed at the program's start), and the process repeats.
*/

#include "Simulation.h"

int main()
{
	Simulation P;
	P.Run();
	return 0;
}