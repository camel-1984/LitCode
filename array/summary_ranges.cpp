#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<string> summaryRanges(vector<int>& nums) {

        vector<string> str;

        if (nums.empty()) {
            return str;
        }

        if (nums.size() == 1) {
            string saegqw = to_string(nums[0]);
            str.push_back(saegqw);
            return  str;
        }

        int j = 0;
        int start = nums[j];
        long long end = start + 1;

        while (j < nums.size()) {
            string stringi;
            if (j+1 < nums.size()){
                if (nums[j+1] == end) {
                    j++;
                    end++;
                } else {
                    end--;
                    if (start == end) {
                        stringi = to_string(start);
                    } else {
                        stringi = to_string(start) + '-' + '>' + to_string(end);
                    }
                    str.push_back(stringi);
                    start = nums[j+1];
                    end = start;

                }
            } else {
                j++;
            }
        }
        end--;
        string stringi;
        if (start == end) {
            stringi = to_string(start);
        } else {
            stringi = to_string(start) + '-' + '>' + to_string(end);
        }
        str.push_back(stringi);
        start = nums[j+1];
        end = start;


        return str;
    }
};

int main() {

    vector<int> nums = {-2147483648,0,2,3,4,6,8,9};

    vector<string> a = Solution::summaryRanges(nums);

    if (a.empty()) {
        std::cout << "empty";
    }

    for (const auto& i : a) {
        std::cout << i << " ";
    }
}






