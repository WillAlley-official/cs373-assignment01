#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
// #include <bits/stdc++.h>
using namespace std;

//@-------------------------------------------@
// GLOBAL VARIABLE DECLARATIONS
//@-------------------------------------------@

string currentLine = "null";

//@-------------------------------------------@
// HELPER FUNCTIONS
//@-------------------------------------------@

//@-------------------------------------------@
// MAIN FUNCTION
//@-------------------------------------------@

int main(int argc, char* argv[]) {
	
	// PHASE 1 : Reading Input File & Building Turing Logic

	// Grab Input File
	ifstream file(argv[1]); 
	
	// Loop to read file line by line and store data into variables
	while(getline(file, currentLine)) {
		istringstream iss(currentLine);
		vector<string> tokens;
		string token;

		while(iss >> token) { tokens.push_back(token); }

		cout << tokens[0] << endl;		
	}	

	// PHASE 2 : Running Input Tape & Determining Result


	// Return
	return 0;
}




