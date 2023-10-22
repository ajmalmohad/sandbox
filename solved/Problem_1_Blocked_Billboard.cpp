#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

void solve(){
    // freopen("billboard.in", "r", stdin);
    // freopen("billboard.out", "w", stdout);

    vector<int> points(12);
    for (int i = 0; i < 12; i++) {
        cin>>points[i];
        points[i] += 1000;
    }
    int count = 0;

    vector<vector<bool>> board(2001, vector<bool>(2001, false));
    for (int i = points[0]; i < points[2]; i++) {
        for (int j = points[1]; j < points[3]; j++) {
            board[i][j] = true;
        }
    }

    for (int i = points[4]; i < points[6]; i++) {
        for (int j = points[5]; j < points[7]; j++) {
            board[i][j] = true;
        }
    }

    for (int i = points[8]; i < points[10]; i++) {
        for (int j = points[9]; j < points[11]; j++) {
            board[i][j] = false;
        }
    }

    for (int i = points[0]; i < points[2]; i++) {
        for (int j = points[1]; j < points[3]; j++) {
            if(board[i][j]) count++;
        }
    }

    for (int i = points[4]; i < points[6]; i++) {
        for (int j = points[5]; j < points[7]; j++) {
            if(board[i][j]) count++;
        }
    }

    cout<<count<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}