#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  // an array is a variable that holds variables
  // it can onlt hold one kid of varbiable at a time

  string favGames[10]; // creating an array of the type string Names with a
                        // size of 10
  int index = 0;
  while (true) {
    cout << "\nwhat would you like to do?\n";
    cout << "Type quit to quit.\n";
    cout << "type add to add a game \n";
    cout << "type show to show your games. \n";
    cout << "type edit to edit last game entered. \n";
    cout << "type find to find a game in the list and edit it\n";

    string input;
    cin >> input;

    if (input == "quit") {
      cout << "Thanks for playing!\n";
      break;
    }
    if (input == "show") {
      for (int i = 0; i < index; i++) {
        cout << favGames[i] << "\n";
      }
    }
    if (input == "add") {
      cout << "Type the name of the game you want ";
      cin >> input;
      favGames[index] = input;
      index++; // Make the index point at the next spot in the array
    }
    if (input == "edit") {
      cout << "Please re-enter last game name!\n";
      cin >> input;
      favGames[index - 1] = input;
    }
    if (input == "edit") {
      cout << "Please re-enter last game name!\n";
      cin >> input;
      favGames[index - 1] = input;
    }
    if (input == "find") {
      cout << "What game would you like to edit?\n";
      cin >> input;
      for (int G = 0; G < index; G++) {
        if (favGames[G] == input) {
          cout << "found it\n";
          cout << "What would you like to chang this to?\n";
          cin >> input;
          favGames[G] = input;
        }
      }
    }
  }
}