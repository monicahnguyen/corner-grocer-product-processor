/*
CS210 Project Three
Corner Grocer Produce Counter
Author: Monica Nguyen
Date: December 10, 2023

Reference:
zyBooks CS210: Programming Languages, Chapter 11.4
"std::out_of_range." cplusplus.com Reference. https://cplusplus.com/reference/stdexcept/out_of_range/
Imran, Neha. (2023) "Capitalizing First Letter in String." DelftStack. https://www.delftstack.com/howto/cpp/cpp-capitalize-first-letter/
*/
#ifndef PRODUCEFREQUENCY_H
#define PRODUCEFREQUENCY_H
#include <iostream>
#include <map>
#include "CornerGrocerFile.h"
using namespace std;

class CGProduce : public CGFile {
public:
	CGProduce(const string& inputFile, const string& outputFile); // constructor
	void DisplayMenu() const; // display menu function
	void PrintSearchItemFrequency(); // function to search frequency of item based on user input
	void PrintItemsList() const; // function to print all items and their frequencies
	void DisplayGraph() const; // function to display histogram of item frequencies
	
private:
	void DisplayBorder(char c, int n) const; // helper function to display menu border
	string searchItem; // variable to search item in the output list
	int searchItemFrequency = 0; // variable for frequency of item purchased
};


// constructor with initialized list
CGProduce::CGProduce(const string& inputFile, const string& outputFile) : CGFile(inputFile, outputFile) {}

// private function to create border for DisplayMenu
void CGProduce::DisplayBorder(char c, int n) const {
	string str = ""; // empty string variable
	int i; // loop variable 

	// append c to string n times
	for (i = 0; i < n; i++) {
		str += c;
	}
	// print the string
	cout << str << endl;
}

// Function to display menu for user selection
void CGProduce::DisplayMenu() const {
	cout << endl;
	DisplayBorder('*', 42); // create menu border
	cout << "* 1 - Count selected produce item" << endl;
	cout << "* 2 - Count all produce items" << endl;
	cout << "* 3 - Display all produce items purchased" << endl;
	cout << "* 4 - Exit program" << endl;
	DisplayBorder('*', 42); // menu border
	cout << "Select an option: "; // prompt user to select option
}

void CGProduce::PrintSearchItemFrequency() {

	// prompt the user to input the item to be searched for frequency
	cout << "Enter the item you would like to search: ";
	cin >> searchItem; // input search item

	searchItem[0] = toupper(searchItem[0]); // capitalize the first letter in searchItem to match map items
	searchItemFrequency = 0; // reset searchItemFrequency to 0 before searching

	try {
		// error checking, throw an exception if item is not in the map
		if (produceMap.count(searchItem) == 0) {
			throw out_of_range("Item not found.");
		}
		else {
			// get the frequency value linked to searchItem in the map
			searchItemFrequency = produceMap.at(searchItem);
		}
	}
	catch (const out_of_range& oor) {
		// print error message if item not found
		cout << "Out of range error: " << oor.what() << endl;
	}
	//print search item frequency
	cout << searchItem << ": " << searchItemFrequency << endl;
}

// print all items and their frequencies
void CGProduce::PrintItemsList() const {
	
	// print title
	cout << endl;
	cout << "ITEMS PURCHASED TODAY" << endl;
	DisplayBorder('-', 24);
	// iterate through the map
	for (auto& producePair : produceMap) {
		// print the results
		cout << producePair.first << " " << producePair.second << endl;
	}
}

void CGProduce::DisplayGraph() const {
	int i; // nested for-loop variable

	for (auto& producePair : produceMap) {
		// print the graph
		cout << producePair.first << " ";
		for (i = 0; i < producePair.second; i++) {
			cout << "#";
		}
		cout << endl;
	}
}

#endif // !PRODUCEFREQUENCY_H


