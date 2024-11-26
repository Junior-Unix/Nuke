#include <iostream>
#include <vector>
#include <fstream>

void writeCombinationsToFile(std::ofstream& file, std::vector<int>& combination, int n, int k) {
    if (k == 0) {
        for (int i = 0; i < combination.size(); ++i) {
            file << combination[i] << " ";
        }
        file << std::endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        combination.push_back(i);
        writeCombinationsToFile(file, combination, n, k - 1);
        combination.pop_back();
    }
}

int main() {
    int n = 6; // Number of faces on the die
    int k = 4; // Number of dice rolls

    std::vector<int> combination;
    std::ofstream file("combinations.txt");

    if (file.is_open()) {
        writeCombinationsToFile(file, combination, n, k);
        file.close();
    } else {
        std::cerr << "Unable to open file";
    }

    return 0;
}