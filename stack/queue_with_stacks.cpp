#include <iostream>

using namespace std;

class MyQueue {
public:

    std::stack<int> st1;
    std::stack<int> st2;

    MyQueue() = default;

    void push(int x) {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop() {
        int a = st1.top();
        st1.pop();
        return a;
    }

    int peek() {
        return st1.top();
    }

    bool empty() {
        if (!st1.empty()) {
            return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
