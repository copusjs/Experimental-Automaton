/*
Author: John Copus
Creation Date: October 21, 2016
Program Name: Automaton - Summation of all neighbors, Mod 10
File Name: Simulation.cpp
Implementations of Note:	The Prompt function requires user input. It appears to be relatively error-proof.
							At the moment, Prompt is the only user input function that checks input size.
Curiosity:
		While Prompt()'s error messages are being displayed, the user can still type inputs, although they will not be immediately visible.
		However, the input will appear when the message clears and the menu appears again. It will appear in the correct place, as if it were typed
		as intended. The console will even accept correct inputs entered this way, and immediately skip the menu to continue with Run().
		Similarly, incorrect inputs can be "stacked", and multiple error messages can be triggered back to back (still accepting inputs the entire time).
*/

#include "Simulation.h"
#include <Windows.h>
#include <iomanip>
#include <string>
#define ITERATIONS		20				//ITERATIONS is the default number of times within Run() that the iteration loops are called, i.e. the length of the main part of the program.
#define ITERATION_PAUSE 400				//ITERATION_PAUSE is the duration (in milliseconds) that a printed grid stays on the screen before the next iteration is printed.
#define ERROR_PAUSE		4000			//In Prompt, ERROR_PAUSE is the duration (in milliseconds) that an error message stays on the screen before the options dialogue reappears.
#define END_PAUSE		3050			//END_PAUSE is the duration (in milliseconds) that the farewell message (user input '9') will remain on the screen before the program exits in debugging mode.
//#define DEBUG							//Used in the Prompt function to help identify possible bugs caused by unusual user inputs.

//-----Constructor Definition-----

Simulation::Simulation()
{
	
	//Set Iteration_Count
	Iteration_Count = ITERATIONS;
}

//-----Destructor Definition-----

Simulation::~Simulation()
{
}

//-----Run Definition-----

void Simulation::Run()
{
	int user_input = this->Prompt();
	switch(user_input)
	{
		case 1:
			Load.Run();
			M.Print_Matrix();
			for(int R = 0; R < Iteration_Count; R++)
			{
				M.Iterate_Matrix();
				Sleep(ITERATION_PAUSE);
				system("cls");
				M.Print_Matrix();
			}
			system("cls");
			this->Run();
			break;
		case 2:
			Load.Run();
			M.Print_Matrix_2();
			for(int R = 0; R < Iteration_Count; R++)
			{
				M.Iterate_Matrix();
				Sleep(ITERATION_PAUSE);
				system("cls");
				M.Print_Matrix_2();
			}
			system("cls");
			this->Run();
			break;
		case 3:
			this->Change_Iteration_Count();
			this->Run();
			break;
		case 4:
			Load.Change_countdown();
			this->Run();
			break;
		case 9:
			cout << "\n\n\tThis is goodbye, for now.\n\n\t";
			Sleep(END_PAUSE);
			break;
		default:
			cout << "\n\n\tI have no idea what's going on :(\n\n\t";
			break;
	}
	return;
}

//-----Prompt Definition-----

int Simulation::Prompt()
{
	string input;
	int input_size;
	int input_int;
	do
	{
		cout << "\n\n\tEnter '1' to start a simulation that prints every number,"
			<< "\n\t\t0 through 9.";
		cout << "\n\n\tEnter '2' to start a simulation that only displays whether"
			<< "\n\t\ta number is non-zero.";
		cout << "\n\n\tEnter '3' to change the number of iterations that the"
			<< "\n\t\tsimulation will cycle through each session.";
		cout << "\n\n\tEnter '4' to change the length of the load screen before"
			<< "\n\t\ta simulation begins running.";
		cout << "\n\n\tEnter '9' to exit.";
		cout << "\n\n\tMake your selection: ";
		while(getline(cin, input) && input.empty())							//Checks if user typed anything before the enter key was pressed.
		{
			system("cls");
			cout << "\n\n\tYou typed nothing.";
			cout << "\n\n\tFrom nothing will come nothing.";
			Sleep(ERROR_PAUSE);
			system("cls");
			cout << "\n\n\tEnter '1' to start a simulation that prints every number,"
				<< "\n\t\t0 through 9.";
			cout << "\n\n\tEnter '2' to start a simulation that only displays whether"
				<< "\n\t\ta number is non-zero.";
			cout << "\n\n\tEnter '3' to change the number of iterations that the"
				<< "\n\t\tsimulation will cycle through each session.";
			cout << "\n\n\tEnter '4' to change the length of the load screen before"
				<< "\n\t\ta simulation begins running.";
			cout << "\n\n\tEnter '9' to exit.";
			cout << "\n\n\tMake your selection: ";
		}
		input_size = input.length();
		input_int = atoi(input.c_str());
#ifdef DEBUG
		cout << "\n\n\tInput Size: " << input_size;
		cout << "\n\n\tInput Value: " << input_int;
		Sleep(5000);
#endif
		if(input_size > 20)
		{
			system("cls");
			cout << "\n\n\tI'm not paying you by the word, you know.";
			Sleep(ERROR_PAUSE);
			system("cls");
		}
		else if(input_size > 1)													//Sanity Check. Inputs with more than one character cannot be a single digit
		{
			system("cls");
			if(input_int == 0)
			{
				cout << "\n\n\tYou're not even typing numbers, are you?";
				cout << "\n\n\tOh well, try again.";
			}
			else
			{
				cout << "\n\n\tYour selection is too long.";
				cout << "\n\n\tLess is more.";
			}
			Sleep(ERROR_PAUSE);
			system("cls");
		}
		else if(input_size == 1)												//Checks single character inputs to see if they convert to a valid int
		{
			if(input_int == 1 || input_int == 2 || input_int == 3 || input_int == 4 || input_int == 9)
			{
				system("cls");
				return input_int;
			}
			else
			{
				system("cls");
				cout << "\n\n\tThere weren't too many options.";
				cout << "\n\n\tKeep it simple.";
				Sleep(ERROR_PAUSE);
				system("cls");
			}
		}
	}while( (input_size > 1) || ( (input_int != 1) && (input_int != 2) && (input_int != 3) && (input_int != 4) && (input_int != 9) ) );
}

//-----Change Iteration Definition-----

void Simulation::Change_Iteration_Count()
{
	string input;
	int input_int;
	do
	{
		cout << "\n\n\tThe current number of iterations is " << Iteration_Count;
		cout << "\n\n\tEnter the number of iterations that you want to see"
			<< "\n\t\twhen the simulation is run: ";
		while(getline(cin, input) && input.empty())							//Checks if user typed anything before the enter key was pressed.
		{
			system("cls");
			cout << "\n\n\tYou typed nothing.";
			cout << "\n\n\tThat's boring to implement, try something else.";
			Sleep(ERROR_PAUSE);
			system("cls");
			cout << "\n\n\tThe current number of iterations is " << Iteration_Count;
			cout << "\n\n\tEnter the number of iterations that you want to see"
				<< "\n\t\twhen the simulation is run: ";
		}
		input_int = atoi(input.c_str());
		if(input_int < 1)
		{
			system("cls");
			cout << "\n\n\tWell, that change...";
			cout << "\n\n\t...is pretty pointless.";
			Sleep(ERROR_PAUSE);
			system("cls");
		}
		else if(input_int > 1500)
		{
			system("cls");
			cout << "\n\n\tThat's a really big number.";
			cout << "\n\n\tTry something smaller.";
			Sleep(ERROR_PAUSE);
			system("cls");
		}
		else
		{
			system("cls");
			Iteration_Count = input_int;
			cout << "\n\n\tThe new number of iterations is " << Iteration_Count;
			cout << "\n\n\tcongratulations";
			Sleep(ERROR_PAUSE);
			system("cls");
		}
	}while(input_int < 1 || input_int > 1500);
	return;
}