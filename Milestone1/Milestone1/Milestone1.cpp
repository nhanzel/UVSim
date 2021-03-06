// Milestone1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int read() {
	int inputInt = 0;
	cout << "Enter an integer: ";
	cin >> inputInt;
	cout << endl;
	return(inputInt);
}

void write(int value, int location) {
	cout << "The contents of location " << location << " is " << value << endl;
}

/*
arithmetic functions
*/

int add(int accumulator, int value) {
	return accumulator + value;
}

int subtract(int accumulator, int value) {
	return add(accumulator, (0 - value));
}

int multiply(int accumulator, int value) {
	cout << accumulator << " * " << value << endl;
	int total = 0;
	for (int i = 0; i < value; ++i) {
		total = (add(total, accumulator));
	}
	return total;
}

int divide(int accumulator, int value) {
	cout << "dividing" << endl;
	int i = 0;
	int remainder = accumulator;
	while (remainder >= value)
	{
		cout << "remainder: " << remainder << "\t" << i << endl;
		remainder = subtract(remainder, value);
		i++;
	}
	return i;
}

//end of arithmetic functions

int main()
{
	const int SIZE = 100;
	int memory[SIZE] = { };
	signed int accumulator = 0;
	int instruction = 0;
	int location = 0;
	int input = 0;
	int count = 0;
	int instCount = 0;

	//intro information
    cout << "*** Welcome to UVSim! ***" << endl;
	cout << "*** Please enter your program one instruction ***" << endl;
	cout << "*** (or data word) at a time into the input   ***" << endl;
	cout << "*** text field. I will display the location   ***" << endl;
	cout << "*** number and a question mark (?). You then  ***" << endl;
	cout << "*** type the word for that location. Enter    ***" << endl;
	cout << "*** -99999 to stop entering your program      ***" << endl << endl;

	//print out the input queue
	int i = 0;
	cout << i << " ? ";
	cin >> input;
	cout << endl;

	//check to see if the user is done
	while (input != -99999) {
		//add instrution to memory
		memory[i] = input;
		count++;
		i++;
		cout << i << " ? ";
		cin >> input;
		cout << endl;
	}

	cout << "*** Program loading completed ***" << endl;
	cout << "*** Program execution begins  ***" << endl;

	i = 0;

	//execute unitl the user halts or until the instructions run out
	while (instruction != 43 && i < count) {

		//parse the instruction and the location
		instruction = memory[i] / 100;
		location = memory[i] % 100;

		//run through all of the possible instructions
		if (instruction == 10) {
			memory[location] = read();
		}
		else if (instruction == 11) {
			write(memory[location], location);
		}
		else if (instruction == 20) {
			accumulator = memory[location];
		}
		else if (instruction == 21) {
			memory[location] = accumulator;
		}
		else if (instruction == 30) {
			accumulator = add(accumulator, memory[location]);
		}
		else if (instruction == 31) {
			accumulator = subtract(accumulator, memory[location]);
		}
		else if (instruction == 32) {
			accumulator = divide(accumulator, memory[location]);
		}
		else if (instruction == 33) {
			accumulator = multiply(accumulator, memory[location]);
		}
		else if (instruction == 40) {
			i = location - 1;
		}
		else if (instruction == 41) {
			if (accumulator < 0)
			{
				i = location - 1;
			}
		}
		else if (instruction == 42) {
			if (accumulator == 0)
			{
				i = location - 1;
			}
		}

		//halt instruction
		else if (instruction == 43) {
			cout << "*** Simpletron execution terminated ***" << endl;
			instCount++;
			break;
		}
		i++;
		instCount++;
	}

	//print out CPU information
	cout << endl;
	cout << "REGISTERS:" << endl;
	cout << "Accumulator:\t\t" << setfill('0') << setw(5) << internal << accumulator << endl;
	cout << "InstructionCounter:\t" << setfill('0') << setw(2) << instCount << endl;
	cout << "InstructionRegister:\t" << memory[i] << endl;
	cout << "OperationCode:\t\t" << instruction << endl;
	cout << "Operand:\t\t" << setfill('0') << setw(2) << location << endl << endl;

	//print out the memory table
	cout << "MEMORY:" << endl;

	cout << "\t00\t01\t02\t03\t04\t05\t06\t07\t08\t09\t" << endl;
	for (int i = 0; i < 10; ++i) {
		cout << (i * 10);
		for (int j = 0; j < 10; ++j) {
			cout << "\t" << setfill('0') << setw(5) << internal << memory[(i * 10) + j];
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
