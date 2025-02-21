#include <iostream>
#include <vector>

int findUnique(const std::vector<int>& nums) {
    int unique = 0;
    for (int num : nums) {
        unique ^= num;
    }
    return unique;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 2, 1};
    std::cout << "Le nombre unique est : " << findUnique(nums) << std::endl;
    return 0;
}