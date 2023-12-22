#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k, temp;
    cin>>n>>k;
    unordered_map<long long, int> record;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        record[temp]++;
    }

    vector<long long> pos, neg;
    for (auto item : record) {
        long long num = item.first;
        if (num < 0) neg.push_back(num);
        else pos.push_back(num);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<int>());

    long long count = 0;
    int start = 0;
    while (start < neg.size()) {
        if (record[neg[start]] >= k) {
            count += 2 * abs(neg[start]);
            record[neg[start]] -= k;
            if (record[neg[start]] == 0) start++;
        }else {
            if (start + 1 < neg.size()) {
                if (record[neg[start + 1]] % k == 0) {
                    count += 2 * abs(neg[start]);
                    record[neg[start]] = 0;
                    start++;
                }
                else {
                    int cumulated = record[neg[start]];
                    record[neg[start]] = 0;
                    start++;
                    while (cumulated < k && start < neg.size()) {
                        if (record[neg[start]] + cumulated < k) {
                            cumulated += record[neg[start]];
                            record[neg[start]] = 0;
                            start++;
                        }else if(record[neg[start]] + cumulated == k){
                            cumulated += record[neg[start]];
                            record[neg[start]] = 0;
                            count += 2 * abs(neg[start]);
                            start++;
                        }else {
                            int taken = k - cumulated;
                            record[neg[start]] -= taken;
                            cumulated = cumulated + taken;
                            count += 2 * abs(neg[start]);
                        }
                    }
                }
            }
            else {
                count += 2 * abs(neg[neg.size() - 1]);
                start++;
            }
        }
    }

    start = 0;
    while (start < pos.size()) {
        if (record[pos[start]] >= k) {
            count += 2 * abs(pos[start]);
            record[pos[start]] -= k;
            if (record[pos[start]] == 0) start++;
        }
        else {
            if (start + 1 < pos.size()) {
                if (record[pos[start + 1]] % k == 0) {
                    count += 2 * abs(pos[start]);
                    record[pos[start]] = 0;
                    start++;
                }
                else {
                    int cumulated = record[pos[start]];
                    record[pos[start]] = 0;
                    start++;
                    while (cumulated < k && start < pos.size()) {
                        if (record[pos[start]] + cumulated < k) {
                            cumulated += record[pos[start]];
                            record[pos[start]] = 0;
                            start++;
                        }else if(record[pos[start]] + cumulated == k){
                            cumulated += record[pos[start]];
                            record[pos[start]] = 0;
                            count += 2 * abs(pos[start]);
                            start++;
                        }else {
                            int taken = k - cumulated;
                            record[pos[start]] -= taken;
                            cumulated = cumulated + taken;
                            count += 2 * abs(pos[start]);
                        }
                    }
                }
            }
            else {
                count += 2 * abs(pos[pos.size() - 1]);
                start++;
            }
        }
    }

    int maxm = 0;
    if(pos.size() && neg.size()){
        maxm = max(pos[pos.size() - 1], abs(neg[neg.size() - 1]));
    }else if(pos.size()){
        maxm = pos[pos.size() - 1];
    }else{
        maxm = abs(neg[neg.size() - 1]);
    }

    count-=maxm;

    cout<<count<<"\n";
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}