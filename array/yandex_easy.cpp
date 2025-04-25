#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string S;
    getline(cin, S);
    string expr;
    for (char c : S) {
        if (!isspace(c)) expr += c;
    }

    stack<int> nums;
    stack<int> ops;
    int i = 0;
    int result = 0;
    int sign = 1;

    while (i < expr.size()) {
        char c = expr[i];
        if (isdigit(c)) {
            long long num = 0;
            while (i < expr.size() && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                ++i;
            }
            result += sign * num;
            continue;
        } else if (c == '+' || c == '-') {
            int localSign = 1;
            while (i < expr.size() && (expr[i] == '+' || expr[i] == '-')) {
                if (expr[i] == '-') localSign *= -1;
                ++i;
            }
            sign = localSign;
            continue;
        } else if (c == '(') {
            nums.push(result);
            ops.push(sign);
            result = 0;
            sign = 1;
            ++i;
        } else if (c == ')') {
            result = nums.top() + ops.top() * result;
            nums.pop();
            ops.pop();
            ++i;
        } else {
            ++i;
        }
    }

    cout << result << endl;
}
