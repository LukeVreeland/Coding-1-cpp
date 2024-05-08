//week 2 coding L

#include <iostream>    // sends text to and from the console
using namespace std;    // we hate typing 'std::' all the freaking time.

int main() {
  cout << "Can you Guess a number?\n";

  // declare a variable of the type string named "playerName";
  string playerName;
  // defining the value of the variable playerName
  playerName = "Player";

  // declare and define a variable of the type boolean named "lightOn"
    // with the value of true.
  // camelCase
  bool lightOn = true;

  // if the (test) is true
  if(lightOn) {
    // do this code
    cout << "1 through 1,000,000,000,000,000 nah im just kidding haha!\n";
  }
  else {
    cout << "It is dark.\n";
  }

  cout << "I am actually thinking of a number between 1 and 10. Can you guess it?\n";
  // set it up at the top of the code
  int theNumber = 4;
  int playerGuess = 0;    // just good practice to define all variables when created.

  cout << "Your guess: ";

  cin >> playerGuess;

  // a single equals is an assignment, a double equals is a comparison.
  // a single equals is "You are...", a double equals is "Are you?"
  if(playerGuess == theNumber) {
    cout << "\nYou've guessed it!\n";
  }
  else {
    cout << "\nNope! " << playerGuess << " was not the number I was thinking of.\n";
  }


}