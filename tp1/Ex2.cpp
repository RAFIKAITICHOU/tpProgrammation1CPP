#include <iostream>
#include <vector>
#include <unordered_set>

void findPairs(const std::vector<int>& nums, int target) {
    std::unordered_set<int> seen;
    for (int num : nums) {
        int complement = target - num;
        if (seen.find(complement) != seen.end()) {
            std::cout << "(" << complement << "," << num << ") ";
        }
        seen.insert(num);
    }
}

int main() {
    std::vector<int> nums = {1, 4, 6, 2, 3, 5, 7};
    int target = 7;
    findPairs(nums, target);
    return 0;
}