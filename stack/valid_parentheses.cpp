#include <iostream>

using namespace std;

class Solution {
public:


    bool isValid(string s) {
        std::stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else if (c == '{') {
                st.push(c);
            } else if (c == '[') {
                st.push(c);
            } else if (c == ')' && !st.empty()) {
                char a = st.top();
                if (a == '('){
                    st.pop();
                    continue;
                } else {return false;}
            } else if (c == '}' && !st.empty()) {
                char a = st.top();
                if (a == '{'){
                    st.pop();
                    continue;
                } else {return false;}
            } else if (c == ']' && !st.empty()) {
                char a = st.top();
                if (a == '['){
                    st.pop();
                    continue;
                } else {return false;}
            } else {
                return false;
            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;

    }
};

int main() {
    return 0;
}
