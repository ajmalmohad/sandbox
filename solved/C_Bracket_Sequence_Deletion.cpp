#include <bits/stdc++.h>
using namespace std;

bool isMatching(string f, string s) {
    int sl = s.size() - 1;
    for (int i = 0; i < f.size(); i++) {
        if (f[i] != s[sl - i]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int start = 0, end = 0;
    int count = 0;
    string firstr = "";
    string second = "";
    int firstrhash = 0;
    int secondhash = 0;
    int mover = 0;

    while (end < n) {
        int i = end - start;
        if (i % 2 == 0) {
            firstrhash += (int)s[(start + end) / 2];
            secondhash += (int)s[end];
            firstr += s[(start + end) / 2];
            second += s[end];
        }
        else {
            secondhash -= (int)second[mover];
            secondhash += (int)s[end];
            second[mover] = 'X';
            second += s[end];
            mover++;
        }

        if (end - start >= 1 && firstrhash == secondhash && isMatching(firstr, second)) {
            end++;
            start = end;
            count++;
            firstr = "";
            second = "";
            firstrhash = 0;
            secondhash = 0;
            mover = 0;
            continue;
        }


        if (end - start == 1 && s[start] == '(' && s[end] == ')') {
            end++;
            start = end;
            count++;
            firstr = "";
            second = "";
            firstrhash = 0;
            secondhash = 0;
            mover = 0;
            continue;
        }

        end++;
    }

    cout << count << " " << end - start << "\n";
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}