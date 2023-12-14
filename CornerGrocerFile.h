/*
CS210 Project Three
Corner Grocer Produce Counter
Author: Monica Nguyen
Date: December 10, 2023

Reference:
zyBooks CS210: Programming Languages, Chapter 11.4
zyBooks CS210: Programming Languages, Chapter 9.2
"const auto& for loop." cplusplus.com Forum. https://cplusplus.com/forum/beginner/252949/
*/
#ifndef CORNERGROCERFILE_H
#define CORNERGROCERFILE_H

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class CGFile {
protected:
	string inputFileName; // protected variable for input file name
	string outputFileName; // protected variable for output file name
	map<string, int> produceMap; // map variable to find produce frequency
	CGFile(const string& input, const string& output); // constructor

private:
	ifstream inputFS; // input file stream
	ofstream outputFS; // output file stream
	string produceItem; // variable for produce item read from input file
	void FileProcessor(); // function to write output data
};

// constructor for files
CGFile::CGFile(const string& input, const string& output) : inputFileName(input), outputFileName(output) {
	// process files
	FileProcessor();
}

// processes input file and writes the results in the output file
void CGFile::FileProcessor() {
	
	// open files
	cout << "Reading file: " << inputFileName << endl;
	inputFS.open(inputFileName); // open input file to read
	outputFS.open(outputFileName); // open output file to write

	// if the file cannot be open then return error message
	if (!inputFS.is_open()) {
		cout << "Error: Could not open file " << inputFileName << "." << endl;
		return; // exit if file results in error
	}

	// read the input file
	while (!inputFS.eof()) {
		// read each produce item in the input file
		inputFS >> produceItem;
		// insert the produce item into the map and count the frequency
		produceMap[produceItem]++;
	}

	inputFS.close(); // close the input file

	// check if the output file is open without errors
	if (outputFS.is_open() && !outputFS.fail()) {
		// iterate through the map
		for (auto& producePair : produceMap) {
			// write the results into the outputfile
			outputFS << producePair.first << ": " << producePair.second << endl;
		}
	}
	
	// display success message if file written successfully
	cout << outputFileName << " has been loaded. Choose from the menu options below." << endl;

	outputFS.close(); // close the output file
}

#endif // !CGFILE_H
