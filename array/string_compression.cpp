#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {

        int write = 0;
        int read = 0;

        int counter = 0;

        while (read < chars.size() - 1) {
            if (chars[read] == chars[read+1]){
                ++counter;
                ++read;
            } else if (counter != 0) {
                ++counter;
                chars[write++] = chars[read];

                string i = to_string(counter);
                for (char j : i) {
                    chars[write++] = j;
                }
                counter = 0;
                ++read;

            } else {
                chars[write++] = chars[read];


                counter = 0;
                ++read;
            }
        }

        if (counter != 0) {
            chars[write++] = chars[read];
            ++counter;

            string i = to_string(counter);
            for (char j : i) {
                chars[write++] = j;

            }
            ++read;

        } else {
            chars[write++] = chars[read];


            ++read;
        }

        if (write < chars.size()) {
            chars.erase(chars.begin() + write, chars.end());
        }

        return chars.size();

        }
};






int main() {

    std::vector<char> vec = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b'};

    Solution sol;
    sol.compress(vec);

    for (auto a : vec) {
        std::cout << a << " ";
    }


    return 0;
}
