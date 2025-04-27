#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, H, N;
    cin >> W >> H >> N;
    if (N == 0) {
        cout << "No\n";
        return 0;
    }

    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;

    int x_min = X1, x_max = X2;
    int y_min = Y1, y_max = Y2;
    int a = X1 + Y1, b = X2 + Y2, c = X1 - Y2, d = X2 - Y1;

    auto feasible = [&]() {
        for (int x = x_min; x <= x_max; ++x) {
            int lowY  = max(y_min,  max(a - x, x - d));
            int highY = min(y_max,  min(b - x, x - c));
            if (lowY <= highY) return true;
        }
        return false;
    };

    for (int i = 2; i <= N; ++i) {
        int NX1, NY1, NX2, NY2;
        cin >> NX1 >> NY1 >> NX2 >> NY2;

        x_min -= 1; x_max += 1;
        y_min -= 1; y_max += 1;
        a     -= 1; b     += 1;
        c     -= 1; d     += 1;

        x_min = max(x_min, NX1);
        x_max = min(x_max, NX2);
        y_min = max(y_min, NY1);
        y_max = min(y_max, NY2);

        if (x_min > x_max || y_min > y_max || !feasible()) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}
