/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  // Generate a random number between 1 and 100.
  srand(time(NULL));
  int randomNumber = rand() % 100 + 1;

  // Ask the user to guess the number.
  cout << "Guess a number between 1 and 100: ";
  int guess;
  cin >> guess;

  // Keep looping until the user guesses the correct number.
  while (guess != randomNumber) {
    if (guess < randomNumber) {
      cout << "Your guess is too low." << endl;
    } else {
      cout << "Your guess is too high." << endl;
    }

    cout << "Guess again: ";
    cin >> guess;
  }

  // The user guessed the correct number.
  cout << "You guessed the correct number!" << endl;

  return 0;
}
