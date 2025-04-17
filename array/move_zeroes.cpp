#include <iostream>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        auto i = nums.begin();
        auto j = nums.begin() + 1;

        while (j != nums.end()) {
            if (*i == 0) {
                if (*j == 0) {
                    ++j;
                } else {
                    std::swap(*i,*j);
                }
            } else {
                ++i;
                ++j;
            }
        }
    }
};

int main() {

    std::vector<int> nums = {0,1,0,3,12};
    Solution sol;
    sol.moveZeroes(nums);



    return 0;
}
