#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cnt(201, 0);

    int ans = 0;

    for (int i = 0; i < n; ++i){

        int p;
        cin >> p;

        for(int v = 1; v < p; v++){
            ans += cnt[v];
        }
        cnt[p]++;
    }

    cout << ans;
    return 0;
}
