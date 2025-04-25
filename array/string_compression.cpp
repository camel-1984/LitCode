#include <iostream>


// using namespace std;
//
// class Solution {
// public:
//     int compress(vector<char>& chars) {
//
//         auto l = chars.begin();
//         auto r = l;
//
//         int c = 0;
//
//         while (r != chars.end()) {
//             if (*l == *r){
//                 ++c;
//                 ++r;
//             } else if (c != 1) {
//                 chars[l - chars.begin()] = *l;
//                 auto i = to_string(c);
//                 for (char j : i) {
//                     chars[l - chars.begin()+1] = j;
//                     ++l;
//                 }
//                 chars.erase(l+1,r);
//
//                 l = r-1;
//                 r = l;
//                 c = 0;
//
//             } else if (c == 1) {
//                 ++l;
//                 r = l;
//                 c = 0;
//             }
//         }
//
//         if  (c != 1) {
//             chars[l - chars.begin()] = *l;
//             auto i = to_string(c);
//             for (auto j : i) {
//                 chars[l - chars.begin()+1] = j;
//                 ++l;
//
//             }
//             chars.erase(l+1,r);
//         }
//         return chars.size();
//
//         }
// };



int main() {

    std::vector<char> vec = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b'};

    Solution sol;
    sol.compress(vec);

    for (auto a : vec) {
        std::cout << a << " ";
    }


    return 0;
}
