#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isSymmetric(const vector<int>& a, int l, int r) {
    if (l != r) {
        while (l < r) {
            if (a[l] != a[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    } else {
        return false;
    }
}

int findLongestPerfectRoute(const vector<int>& a) {
    unordered_map<int, vector<int>> positions;
    for (int i = 0; i < a.size(); ++i) {
        positions[a[i]].push_back(i);
    }

    int max_len = 0;
    for (const auto& entry : positions) {
        const vector<int>& pos = entry.second;
        int m = pos.size();
        for (int i = 0; i < m; ++i) {
            for (int j = m - 1; j >= i; --j) {
                int l = pos[i];
                int r = pos[j];
                int current_len = r - l + 1;
                if (current_len <= max_len) {
                    break;
                }
                if (isSymmetric(a, l, r)) {
                    max_len = max(max_len, current_len);
                    break;
                }
            }
        }
    }

    return max_len;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << findLongestPerfectRoute(a) << endl;

    return 0;
}