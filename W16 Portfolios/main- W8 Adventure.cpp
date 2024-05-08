#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to roll a die with given number of sides (default is 6)
int RollDie(int sides = 6) {
    return rand() % sides + 1;
}

// Function to ask a yes/no question and return the response
string askYesNo(string question) {
    string response;
    cout << question << " (yes/no): ";
    cin >> response;
    return response;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    int health = 10;
    int gold = 0;
    int turns = 0;
    bool alive = true;

    do {
        turns++;
        string response = askYesNo("Would you like to go adventuring?");
        if (response == "yes") {
            int orcAttack = RollDie();
            int playerBlock = RollDie();
            if (playerBlock >= orcAttack) {
                cout << "You successfully blocked the orc's attack and ran away!\n";
                health--;
                gold += RollDie(10); // Random gold between 1 and 10
            } else {
                health -= orcAttack;
                cout << "You failed to block the orc's attack! You lose " << orcAttack << " health points.\n";
            }
        } else {
            break;
        }

        if (health <= 0) {
            alive = false;
            break;
        }

    } while (true);

    if (alive) {
        cout << "You are still alive!\n";
        cout << "You lasted " << turns << " turns.\n";
        cout << "You found " << gold << " gold.\n";
        if (health < 5) {
            cout << "Your health is low. Consider going to the doctor.\n";
        }
    } else {
        cout << "You died!\n";
        cout << "You had " << gold << " gold on you.\n";
    }

    return 0;
}


