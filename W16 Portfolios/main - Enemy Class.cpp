#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Initialize random seed
    srand(time(0));

    // Initialize player and enemy health
    int playerHealth = 100;
    int enemyHealth = 50;

    // Battle loop
    while (playerHealth > 0 && enemyHealth > 0) {
        // Player's turn
        int choice;
        std::cout << "Player's turn:" << std::endl;
        std::cout << "1. Attack" << std::endl;
        std::cout << "2. Use Consumable" << std::endl;
        std::cin >> choice;

        if (choice == 1) {
            // Simulate player attack
            int damage = rand() % 20 + 10; // Random damage between 10 to 30
            enemyHealth -= damage;
            std::cout << "Player attacks and deals " << damage << " damage!" << std::endl;
        } else if (choice == 2) {
            // Simulate using a consumable
            int healthRestored = rand() % 20 + 10; // Restore between 10 to 30 health
            playerHealth += healthRestored;
            std::cout << "Player uses a consumable and restores " << healthRestored << "     health." << std::endl;
        } else {
            std::cout << "Invalid choice. Skipping turn." << std::endl;
        }

        // Check if enemy is defeated
        if (enemyHealth <= 0) {
            std::cout << "Player wins!" << std::endl;
            break;
        }

        // Enemy's turn
        int enemyDamage = rand() % 20 + 10; // Random damage between 10 to 30
        playerHealth -= enemyDamage;
        std::cout << "Enemy attacks and deals " << enemyDamage << " damage!" << std::endl;

        // Check if player is defeated
        if (playerHealth <= 0) {
            std::cout << "Enemy wins!" << std::endl;
            break;
        }
    }

    return 0;
}