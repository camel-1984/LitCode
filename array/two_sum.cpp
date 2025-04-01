#include <iostream>
#include <unordered_map>


class Solution {
public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target) {

        std::vector<int> vec;
        std::unordered_map<long, int> map;

        for (size_t i = 0; i < nums.size(); i++) {
            long dif = target - nums[i];
            if (map.contains(dif)) {
                vec.push_back(map[dif]);
                vec.push_back(static_cast<int>(i));
                break;

            } else {
                map.emplace(nums[i], i);
            }
        }
        return vec;
    }
};


int main() {
    std::vector<int> nums = {2,7,11,15};
    int target = 9;

    std::vector<int> vec = Solution::twoSum(nums,target);

    for (auto i : vec) {
        std::cout << i;
        if (i != vec.size()-1) {
            std::cout << " ";
        }
    }

    return 0;
}
