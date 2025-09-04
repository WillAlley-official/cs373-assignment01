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
	
////// PHASE 1 : Reading Input File & Building Turing Logic

	// Grab Input File
	ifstream file(argv[1]); 
	
	// Loop to read file line by line and store data into variables
	while(getline(file, currentLine)) {
		istringstream iss(currentLine);
		vector<string> tokens;
		string token;

		while(iss >> token) { tokens.push_back(token); }

		// For State Definitions:
		int index = stoi(tokens[1]);
		if(tokens[0] == "state") {

			stateType[index] = tokens[2];

		// For Transition Definitions:
		} else {

			// Creates new State node
			State* newState = new State();
			char c = tokens[2][0];
			newState->currTapeValue = c;
			int num = stoi(tokens[3]);
			newState->destinationState = num;
			c = tokens[4][0];	
			newState->newTapeValue = c;
			c = tokens[5][0];	
			newState->tapeMovement = c;

			// Puts new State into array
			if(transitionData[index] == nullptr) {
				transitionData[index] = newState;
			} else {
				State* temp = transitionData[index];
				while(temp->next != nullptr) temp = temp->next;
				temp->next = newState;
			}	
	
			delete newState;
		}
	}	

////// PHASE 2 : Converting Tape Input Into a Vector

	// Grabs tape from command line.
	string inputTape = argv[2];
	int tapeLength = inputTape.size();

	// Creates vector of chars to store tape in.
	vector<char> tape;
	for(int i=0; i<tapeLength; i++) {
		tape.push_back(inputTape[i]);
	}

////// PHASE 3 : Running Input Tape & Determining Result

	// Locate Start State
	int startStateIndex = 0;
	for(int i=0; i<1001; i++) {
		if(stateType[i] == "start") {
			startStateIndex = i;
			break;
		}
	}

	// Loop for Traversing the Turing Machine
	int maxTransitions = stoi(argv[3]);
	for(counter = 0; counter < maxTransitions; counter++) {
		
		// Read Tape Head
		// Locate Transition Node @ Current State
		// Replace Tape Head
		// Move Tape Head
		// Move States 
	}

////// PHASE 4 : Printing Turing Machine Output

	// Return
	return 0;
}




