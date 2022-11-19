#include <iostream>
#include <string>
using namespace std;

/*
Won't Work
*/
void reversestr(string& s, int start, int end) {
    for (int i = start; i <= (start + end) / 2; i++) {
        char temp = s[i];
        s[i] = s[end - (i - start)];
        s[end - (i - start)] = temp;
    }
}

char opposite(char val) {
    return val == '1' ? '0' : '1';
}

void solve() {
    int n;
    string s, temp;
    cin >> n;
    cin >> temp;
    int count = 0, minim = INT32_MAX;

    s = '0' + temp + '1';
    for (int i = 1; i < s.size(); i++){
        if(s[i]==s[i-1]) count++;
    }
    count/=2;
    minim = min(minim, count);

    count=0;
    s = '1' + temp + '0';
    for (int i = 1; i < s.size(); i++){
        if(s[i]==s[i-1]) count++;
    }
    count/=2;
    minim = min(minim, count);

    cout << minim << "\n";
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}


// We need to make our string alternating, i.e.si≠si + 1. When we reverse substring sl…sr, we change
// no more than two pairs sl−1, sl and sr, sr + 1. Moreover, one pair should be a consecutive pair 00
// and other — 11. So, we can find lower bound to our answer as maximum between number of pairs of 00
// and number of pairs of 11. And we can always reach this lower bound, by pairing 00 with 11 or with
// left / right border of s.

// Another way to count the answer is next: suppose we want to make string 0101..., then let's transform
// s to 1 + s + 0. For example, if s= 0110, we will get 101100. We claim that after this transformation,
// we will have equal number of 00 and 11, so the answer is the number of consecutive pairs of the same
// character divided by two. The answer is the minimum between answers for 1 + s + 0 and 0 + s + 1.

