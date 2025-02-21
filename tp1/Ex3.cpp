#include <iostream>
#include <vector>

void rearrangeEvenOdd(std::vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        if (nums[left] % 2 == 0) {
            left++;
        } else {
            std::swap(nums[left], nums[right]);
            right--;
        }
    }
}

int main() {
    std::vector<int> nums = {3, 8, 5, 2, 4, 7};
    rearrangeEvenOdd(nums);
    for (int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}