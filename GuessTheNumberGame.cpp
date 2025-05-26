#include <iostream> // required to use 'cout' and 'cin'
#include <string> // required for getline with strings ('cin' will allow spaces)
#include <cstdlib> // required for rand() and srand() *random numbers*
#include <ctime> // required for time() and to help generate randomness of numbers
using namespace std;

int main() {

	srand(time(0)); // Seeds randomness
	char replay; // Letter character associated with replaying the game

	do {
		int randomNum = rand() % 100 + 1; // Get number between 1 and 100
		int num;

		cout << "Let's play a game. I'm thinking of a number between 1 and 100." << endl; // First prompt when game starts
		cout << "Take a guess: "; // Asks user to input first guess

		while (!(cin >> num)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input. Please enter a number: "; // Prompts user to input valid guess
		}

		while (num != randomNum) {
			if (num < randomNum) {
				cout << "Too low. Try again: "; // Prompts user their guess is too low and to try again
			}
			else if (num > randomNum) {
				cout << "Too high. Try again: "; // Prompts user their guess is too high and to try again
			}

			while (!(cin >> num)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input. Please enter a number: "; // Prompts user to input valid guess
			}
		}

		cout << "CORRECT! The number was: " << randomNum << endl; // Prompts user their guess is correct
		cout << "Would you like to play again?: "; // Asks user if they want to play again
		cin >> replay;

		while (cin.fail() || (replay != 'y' && replay != 'Y' && replay != 'n' && replay != 'N')) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input. Please enter 'Y' or 'N': "; // Checks if user input is valid and prompts user if it's not
		}

		if (replay == 'y' || replay == 'Y') {
			cout << endl; // Adds blank space to separate games
		}

	} while (replay == 'y' || replay == 'Y');

	if (replay == 'n' || replay == 'N') {
		cout << "Thank you for playing. See you next time!";
	}
}