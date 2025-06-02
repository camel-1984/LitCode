#include <iostream>

using namespace std;

class Solution {
public:
    static bool isPalindrome(int x) {
        string st = to_string(x);
        if (st.length() == 1) {
            return true;
        }
        auto l = 0;
        auto r = st.length()-1;

        while (l <= r) {
            if (st[l] != st[r]) { return false;}
            l++;
            r--;
        }

        return true;
        
    }
};

int main() {
    int u;
    cin >> u;
    if (Solution::isPalindrome(u)) {
        std::cout << "yes";
    }
    
}