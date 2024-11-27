#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    std::ofstream file("dice_rolls.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    file << "Roll,Result\n";
    std::srand(std::time(0));

    for (int i = 1; i <= 4; ++i) {
        int roll = std::rand() % 6 + 1;
        file << i << "," << roll << "\n";
    }

    file.close();
    std::cout << "Dice rolls saved to dice_rolls.csv" << std::endl;

    return 0;
}