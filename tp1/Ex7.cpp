#include <iostream>
#include <vector>

void maxSumRow(const std::vector<std::vector<int>>& jaggedArray) {
    int maxSum = 0;
    int maxRow = 0;
    for (size_t i = 0; i < jaggedArray.size(); i++) {
        int sum = 0;
        for (int num : jaggedArray[i]) {
            sum += num;
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }
    std::cout << "La ligne avec la plus grande somme est la ligne " << maxRow + 1 << " avec une somme de " << maxSum << std::endl;
}

int main() {
    std::vector<std::vector<int>> jaggedArray = {
        {2, 5},
        {1, 2, 3, 4},
        {1, 1, 3}
    };
    maxSumRow(jaggedArray);
    return 0;
}