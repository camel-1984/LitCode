#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        std::string result;
        for (char ch : s) {
            if (std::isalpha(ch)) {
                result += std::tolower(ch);
            } else if (std::isdigit(ch)) {
                result += ch;
            }
        }

        int l = 0;
        int r = result.size() - 1;
        while (l < r) {
            if (result[l] != result[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

int main() {

    string a = "QZrD2 7UL91z,i`O2ef:6e'2\"yP !:,U.:pX90PU3CXo'i!;3 `j 0?\"'hK8 ? BAjM2\"DBw?7!4R3?U2E8F2y!?3 R2!fw 6e!:0  ErCi98KM`,8`8648,mi3P0`,!5 E.?00J3A 52\"x8,tHy!'2!DLBbK'j!tt1C' 7`JPulW\"\"uRTbr\"',\",U`ZOW5'\"LMDQDMJ\"'5WOZ`U,\",'\"rbTRu\"\"WluPJ`7 'C1tt!j'KbBJD!2'!yHt,8x\"25 A3J00?.E 5!,`0P3im,8468`8,`MK89iCrE  0:!e6 wf!2R 3?!y2F8E2U?3R4!7?wBD\"2MjAB ? 8Kh'\"?0 j` 3;!i'oXC3UP09Xp:.U,:! Py\"2'e6:fe2O`i,z19LU7 2DrZQ";

    // Solution::isPalindrome(a);

    return 0;
}
