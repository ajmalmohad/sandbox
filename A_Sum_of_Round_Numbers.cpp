#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums;
    if (n < 10) {
        cout << 1 << '\n' << n << '\n';
    }
    else {
        int temp = n;
        int multiplicant = 1;
        while (temp) {
            int remainder = temp % 10;
            temp /= 10;
            if (remainder) {
                nums.push_back(multiplicant * remainder);
            }
            multiplicant *= 10;
        }
        cout << nums.size() << "\n";
        for (int x : nums) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}