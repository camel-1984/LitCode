#include <iostream>
#include <stack>
#include <vector>

class RecentCounter {
public:
    RecentCounter() = default;

    std::stack<int> counter;

    int ping(int t) {
        std::vector<int> popped = {};
        int c = 0;
        counter.push(t);
        popped.push_back(counter.top());
        counter.pop();
        c++;
        if (!counter.empty()) {
            while (t - 3000 <= counter.top() && counter.top() <= t) {
                popped.push_back(counter.top());
                counter.pop();
                c++;
                if (counter.empty()) {
                    break;
                }
            }
        }
        for (int i = popped.size()-1; i >= 0; --i) {
            counter.push(popped[i]);
        }
        return c;
    }
};

// class RecentCounter {
// private:
// std::vector<int> records;
// int start;
//
// public:
// RecentCounter() : start(0) {}
//
// int ping(int t) {
//     records.push_back(t);
//     while (records[start] < t - 3000) {
//         start++;
//     }
//     return records.size() - start;
// }
// };

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {

    RecentCounter recent_counter;
    std::cout << recent_counter.ping(100) << '\n';
    std::cout << recent_counter.ping(1000) << '\n';
    std::cout << recent_counter.ping(2000) << '\n';
    std::cout << recent_counter.ping(3000) << '\n';
    std::cout <<recent_counter.ping(3200) << '\n';

    return 0;
}
