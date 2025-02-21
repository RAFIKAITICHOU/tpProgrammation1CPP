#include <iostream>
#include <vector>

void sumRows(const std::vector<std::vector<int>>& jaggedArray) {
    for (size_t i = 0; i < jaggedArray.size(); i++) {
        int sum = 0;
        for (int num : jaggedArray[i]) {
            sum += num;
        }
        std::cout << "Somme de la ligne " << i + 1 << " : " << sum << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> jaggedArray = {
        {1, 2, 3},
        {4, 5},
        {6, 7, 8, 9}
    };
    sumRows(jaggedArray);
    return 0;
}