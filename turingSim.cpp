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

// State Structure
struct State {
	char currTapeValue = '\0';
	int destinationState = -1;
	char newTapeValue = '\0';
	char tapeMovement = '\0';
	State* next = nullptr;
};

// Variables
string currentLine = "null";
int tapeHead = 0;
State* currState = nullptr;
int counter = 0;

// State Arrays
string stateType[1001];
State* transitionData[1001];

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

		// For State Definitions:
		if(tokens[0] == "state") {

			int index = stoi(tokens[1]);
			stateType[index] = tokens[2];

		// For Transition Definitions:
		} else {

			State* newState = new State();
			char c = tokens[2][0];
			newState->currTapeValue = c;
			int num = stoi(tokens[3]);
			newState->destinationState = num;
			c = tokens[4][0];	
			newState->newTapeValue = c;
			c = tokens[5][0];	
			newState->tapeMovement = c;

			// TODO: Finish setting up the transitionData array!	
	
			delete newState;
		}
	}	

	// PHASE 2 : Running Input Tape & Determining Result


	// Return
	return 0;
}




