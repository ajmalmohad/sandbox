#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
const long long mod = 1e9+7;

int backtrack(vector<string>& board, int i, int j, pair<int, int> barn, int count){
    if(i > 9 || j > 9 || i < 0 || j < 0) return 1e9;
    if(board[i][j] == 'R' || board[i][j] == 'C') return 1e9;
    if(count > 0 && board[i][j] == 'L') return 1e9;
    if(board[i][j] == 'B') return count;

    cout<<i<<" "<<j<<"\n";
    if(board[i][j] != 'L') board[i][j] = 'C';
    int up = 1e9, down = 1e9, left = 1e9, right = 1e9;  
    if(i+1 < 9) down = backtrack(board, i+1, j, barn, count+1);
    if(i-1 >= 0) up = backtrack(board, i-1, j, barn, count+1);
    if(j+1 < 9) right = backtrack(board, i, j+1, barn, count+1);
    if(j-1 >= 0) left = backtrack(board, i, j-1, barn, count+1);

    return min(down, min(up, min(left, right)));
}

void solve(){
    vector<string> board(10);
    pair<int, int> lake;
    pair<int, int> barn;
    bool lakefound = false;
    bool barnfound = false;
    for (int i = 0; i < 10; i++) {
        cin>>board[i];
        if(!lakefound || !barnfound){
            for (int j = 0; j < 10; j++){
                if(board[i][j] == 'L') {
                    lake = {i, j};
                    lakefound = true;
                }else if(board[i][j] == 'B'){
                    barn = {i, j};
                    barnfound = true;
                }
            }
        }
    }

    cout<<backtrack(board, lake.first, lake.second, barn, 0)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}