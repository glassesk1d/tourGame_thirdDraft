/*
	Amariah Harper
	Summer 2022 Submission - Edited 10/6/2022
	random numbers, arrays, and sounds || UAT Tour Game
*/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;




int main() {

	srand(time(0));
	for (int a = 0; a <= 0; a++) {
		//varibles that represents the users input
		int userIn;
		char userChoice;

		//used to tell the user which room they entered
		string room[20] = { "106","107","108","135","201","202", "203", "204", "205",
			"206", "207", "208", "251", "232", "234", "235", "244", "245", "252", "253" };

		//used to tell the user which professor is in the room with them
		string prof[10] = { "Beam", "Bolman", "Brokaw", "Clark", "Cofrancesco", "Moore",
			"Prater", "Glover", "Understiller", "Valenzuela" };

		//used to tell the user what their grade is
		string grade[5] = { "A", "B", "C", "D" , "F" };

		//the varible will be used to set the users current grade
		int l = 2;

		//will be used to determine if a professor is inside a room
		int whichProf;

		//will be used to determine which professor is inside a room
		int isProfPresent;

	
		cout << "Get to know UAT by visiting our classroms and professors." << endl <<
			"You'll have a letter grade that will go up or down based on whether or not a professor is inside." << endl
			<< "Your grade is a " << grade[l] << " right now. Pick a clssroom by giving me a number 1 - 20" << endl;

		//while the users grade is between A and F the loop will run
		while ((0 < l) && (l < 4)) {
			for (int b = 0; b <= 0; b++) {
				cout << "Give me a number, 1 - 20" << endl;
				cin >> userIn;
				if (userIn >= 1 && userIn <= 20) {
					int userGuess = userIn - 1;
					cout << "You chose room " << room[userGuess] << "...";
				}
				else {
					cout << "invalid input. pick a number 1-20" << endl;
					b--;
				}
			}
			//determines if a professor is in the room associated with the chosen number randomly
			isProfPresent = (rand() % 2) + 1;
			//if a professor is inside:
			if (isProfPresent == 1) {
				//waits a bit before running the rest of the program
				Sleep(2);
				//plays a noise
				Beep(750, 800);
				//brings up the users letter grade
				--l;
				//determines which professor is inside the room randomly
				whichProf = (rand() % 10);
				cout << " professor " << prof[whichProf] << " is inside.";
			}
			//if a professor isn't inside:
			else {
				//waits two seconds before running the rest of the program
				Sleep(2);
				//plays a noise
				Beep(750, 800);
				//lowers the users grade by a letter
				++l;
				cout << " no one was inside.";
			}
			cout << " Your grade is " << grade[l] << endl;
		}
		//if the users grade is an A
		if (l == 0) {
			cout << "YOU WIN!!" << endl;
		}
		//if the users grade is a F
		else if (l == 4) {
			cout << "YOU LOSE" << endl;
		}

		for (int c = 0; c <= 0; c++) { //asks if the student would like to play again. Will ask the question if user 
										//types something other than 'y' or 'n'
			cout << "The game is over. Would you like to play again?" << endl;
			cin >> userChoice;
			if (userChoice == 'n') {
				cout << "Thank's for playing!" << endl;
			}
			else if (userChoice == 'y') {
				cout << "Wait one moment..." << endl << endl;
				a--;
			}
			else {
				cout << "invaid input. Type 'y' or 'n' to answer" << endl;
				c--;
			}
		}

	}
	return 0;
}
