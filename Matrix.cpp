/*
Author: John Copus
Creation Date: October 21, 2016
Program Name: Automaton - Summation of all neighbors, Mod 10
File Name: Matrix.cpp
*/

#include "Matrix.h"
//#define DEBUG2						//Used in the Iterate_Matrix function to debug changing the grid length and width.

//-----Constructor Definition-----

Matrix::Matrix()
{
	//Set grid initial values
	for(int i = 0; i < GRID_LENGTH; i++)
	{
		for(int j = 0; j < GRID_WIDTH; j++)
		{
			grid[i][j] = (i * j) % 10;
		}
	}
	return;
}

//-----Destructor Definition-----

Matrix::~Matrix()
{
}

//-----First Print Definition-----

void Matrix::Print_Matrix()
{
	cout << "\n\n";
	for(int i = 0; i < GRID_LENGTH; i++)
	{
		cout << "    ";
		for(int j = 0; j < GRID_WIDTH; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}

//-----Second Print Definition-----

void Matrix::Print_Matrix_2()
{
	cout << "\n\n";
	for(int i = 0; i < GRID_LENGTH; i++)
	{
		cout << "    ";
		for(int j = 0; j < GRID_WIDTH; j++)
		{
			if(grid[i][j] != 0)
			{
				cout << "x ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
	cout << endl;
	return;
}

//-----Iterate Definition-----

void Matrix::Iterate_Matrix()
{
	int sum;
	int Temp[GRID_LENGTH][GRID_WIDTH] = {0};				//for storing the newly iterated values of the grid (think Game of Life)

	//Generate iterated values, stored in Temp grid

	for(int i = 0; i < GRID_LENGTH; i++)
	{
		for(int j = 0; j < GRID_WIDTH; j++)
		{
			sum = 0;
			sum += grid[i][j];
			
			//Checking a[i-1][j-1]
			
			if(i > 0 && j > 0)								{	sum += grid[i-1][j-1];		}

			//Checking a[i-1][j]

			if(i > 0)										{	sum += grid[i-1][j];		}

			//Checking a[i-1][j+1]

			if(i > 0 && j < GRID_WIDTH - 1)					{	sum += grid[i-1][j+1];		}

			//Checking a[i][j-1]

			if(j > 0)										{	sum += grid[i][j-1];		}

			//Checking a[i][j+1]

			if(j < GRID_WIDTH - 1)							{	sum += grid[i][j+1];		}

			//Checking a[i+1][j-1]
			
			if(i < GRID_LENGTH - 1 && j > 0)				{	sum += grid[i+1][j-1];		}

			//Checking a[i+1][j]
			
			if(i < GRID_LENGTH - 1)							{	sum += grid[i+1][j];		}
			
			//Checking a[i+1][j+1]
			
			if(i < GRID_LENGTH - 1 && j < GRID_WIDTH - 1)	{	sum += grid[i+1][j+1];		}
			
			sum = sum % 10;
			Temp[i][j] = sum;
		}
	}

#ifdef DEBUG2
	cout << "\n\n\tTemp array";
	cout << "\n\n";
	for(int i = 0; i < GRID_LENGTH; i++)
	{
		cout << "\t";
		for(int j = 0; j < GRID_WIDTH; j++)
		{
			cout << Temp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
#endif

	//Copy Temp grid's iterated values into Matrix

	for(int i = 0; i < GRID_LENGTH; i++)
	{
		for(int j = 0; j < GRID_WIDTH; j++)
		{
			grid[i][j] = Temp[i][j];
		}
	}
	return;
}