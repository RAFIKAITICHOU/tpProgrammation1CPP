#include <iostream>
#include <vector>
#include <climits>

void maxSubArray(const std::vector<std::vector<int>>& matrix) {
    int maxSum = INT_MIN;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int left = 0; left < m; left++) {
        std::vector<int> temp(n, 0);
        for (int right = left; right < m; right++) {
            for (int i = 0; i < n; i++) {
                temp[i] += matrix[i][right];
            }
            int currentSum = 0, maxCurrent = INT_MIN;
            for (int num : temp) {
                currentSum = std::max(num, currentSum + num);
                maxCurrent = std::max(maxCurrent, currentSum);
            }
            maxSum = std::max(maxSum, maxCurrent);
        }
    }
    std::cout << "Somme maximale : " << maxSum << std::endl;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {-2, 1, -3, 4},
        {-1, 2, 1, -5},
        {4, -1, 2, 1}
    };
    maxSubArray(matrix);
    return 0;
}