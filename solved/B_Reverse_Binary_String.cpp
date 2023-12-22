#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int count = 0;

    for (int i = 1; i < s.size(); i++){
        if(s[i]==s[i-1]) count++;
    }

    count = ceil((float)count/2);
    cout << count << "\n";
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}
