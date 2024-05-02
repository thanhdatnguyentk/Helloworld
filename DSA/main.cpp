#include <iostream>
#include <string>
#include <vector>

std::vector<int> findPositions(int x, int i) {
    std::string xStr = std::to_string(x);
    std::string iStr = std::to_string(i);

    std::vector<int> positions;
    size_t position = xStr.find(iStr);
    while (position != std::string::npos) {
        positions.push_back(position);
        position = xStr.find(iStr, position + 1);
    }

    return positions;
}

int main() {
    int x, i;
    std::cout << "Enter the number x: ";
    std::cin >> x;
    std::cout << "Enter the number i: ";
    std::cin >> i;

    std::vector<int> positions = findPositions(x, i);
    if (!positions.empty()) {
        std::cout << "Positions of " << i << " in " << x << " are: ";
        for (int position : positions) {
            std::cout << position << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << i << " not found in " << x << std::endl;
    }

    return 0;
}