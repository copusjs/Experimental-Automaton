/*
Author: John Copus
Creation Date: October 21, 2016
Program Name: Automaton - Summation of all neighbors, Mod 10
File Name: Matrix.h
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;
#define GRID_LENGTH		37		//within for-loops, this constant is associated with the 'i' loop variable, i.e. it increments once for every completed WIDTH loop. Top of the screen to the bottom.
#define GRID_WIDTH		37		//within for-loops, this constant is associated with the 'j' loop variable. It is printed across the screen, left to right.

class Matrix
{
	private:
		int grid[GRID_LENGTH][GRID_WIDTH];
	public:
		Matrix();
		~Matrix();
		void Print_Matrix();							//Prints the Matrix to the console. All values are printed.
		void Print_Matrix_2();							//Prints the Matrix to the console. Only specified values are printed; a blank space is printed for all other values.
		void Iterate_Matrix();							//Iterates the Matrix (summation, new value assignment, etc.)
};

#endif