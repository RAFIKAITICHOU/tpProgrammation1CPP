#include <iostream>
#include <vector>
#include <unordered_set>

bool isPermutation(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    std::unordered_set<int> nums;
    for (int i = 1; i <= n * n; i++) {
        nums.insert(i);
    }
    for (const auto& row : matrix) {
        for (int num : row) {
            if (nums.find(num) == nums.end()) {
                return false;
            }
            nums.erase(num);
        }
    }
    return nums.empty();
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::cout << (isPermutation(matrix) ? "C’est une permutation." : "Ce n’est pas une permutation.") << std::endl;
    return 0;
}