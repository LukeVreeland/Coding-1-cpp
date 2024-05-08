#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;
string favGames[100];
int index = 0;
string input;
ofstream file;
void options() {
  cout << "what would you like to do?\n";
  cout << "Type Stop to Stop.\n";
  cout << "type add to add games to the list \n";
  cout << "type show to show games. \n";
  cout << "type edit to edit list. \n";
  cout << "type remove to remove a game from list.\n";
  cout << "type save to save list.\n";
  cout << "Type load to load list.\n";
}
void add() {
  while (true) {
    cout << "what game would you like to add?\n";
    getline(cin, input);
    if (input == "stop") {
      break;
    } else if (input == "") {
      cout << "Please enter a valid game name.\n";
      continue;
    }
    favGames[index] = input;
    index++;
  }
}
void showList() {
  for (int i = 0; i < index; i++) {
    cout << favGames[i] << "\n";
  }
}
void editList() {
  cout << "What game would you like to edit?\n";
  cin >> input;
  for (int i = 0; i < index; i++) {
    if (favGames[i] == input) {
      cout << "found it\n";
      cout << "What would you like to chang this to?\n";
      cin >> input;
      favGames[i] = input;
    }
  }
}
void saveList() {
  file.open("save.txt");
  for (int i = 0; i < index; i++) {
    file << favGames[i] << "\n";
  }
  file.close();
  cout << "Your list has be saved.\n";
}
void loadList() {
  string line;
  ifstream save("save.txt");
  if (save.is_open()) {
    index = 0;
    while (getline(save, line) && index < 100) {
      favGames[index++] = line;
    }
    save.close();
  } else {
    cout << "file could not be loaded.\n";
  }
}
void removeGame() {
  cout << "What game would you like to remove?\n";
  cin >> input;
  for (int i = 0; i < index; i++) {
    if (favGames[i] == input) {
      for (int j = i; j < index - 1; j++) {
        favGames[j] = favGames[j + 1];
      }
      index--;
      cout << input << " has been removed from the list.\n";
      return;
    }
  }
  cout << input << " was not found in the list.\n";
}
int main() {
 

  while (true) {
    options();
    cin >> input;
    if (input == "show") {
      showList();
    } else if (input == "add") {
      add();
    } else if (input == "edit") {
      editList();
    } else if (input == "save") {
      saveList();
    } else if (input == "load") {
      loadList();
    } else if (input == "remove") {
      removeGame();
    } else if (input == "stop") {
      break;
    }
  }
}
