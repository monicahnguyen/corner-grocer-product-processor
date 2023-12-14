/*
CS210 Project Three
Corner Grocer Produce Counter
Author: Monica Nguyen
Date: December 10, 2023
*/

#include <iostream>
#include "ProduceFrequency.h"

using namespace std;


int main() {
	int userSelection = 0; // variable for user input initialized at 0
	CGProduce produceResults = CGProduce("CS210_Project_Three_Input_File.txt", "frequency.dat"); // produce results instance
	
	// do-while loop to display the menu and prompt the user to make a selection
	do {
		produceResults.DisplayMenu();
		cin >> userSelection;

		switch (userSelection) {
			case 1:
				// Prompt a user to input the item, or word, they wish to look for.
				// Return a numeric value for the frequency of the specific word.
				produceResults.PrintSearchItemFrequency();
				break;

			case 2:
				// print item list with frequency
				produceResults.PrintItemsList();
				break;

			case 3:
				// print item list histogram
				produceResults.DisplayGraph();
				break;
				
			case 4:
				// Exit the program
				cout << "Thanks for using the Corner Grocer Produce Counter. Exiting the program." << endl;
				break;

			default:
				if (userSelection) {
					// if userSelection is not within range, print error message
					cout << "Error: Selection is not within range. Please select from the menu options." << endl;
				}
				else {
					// if userSelection is not valid data type, print error message
					cout << "Error: Invalid input. Please select from the menu options." << endl;
					cin.clear(); // clears input clear fail flags
					while (cin.get() != '\n'); // clear out any remaining characters in the invalid input
				}
				continue;
		}
	} while (userSelection != 4);
	return 0;
}