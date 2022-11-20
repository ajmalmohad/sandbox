#include <bits/stdc++.h>
using namespace std;

int main() {
    float l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    for (int i = x; i <= y; i++) {
        float experience = k * i;
        if ((experience == floor(experience)) && experience >= l && experience <= r) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}