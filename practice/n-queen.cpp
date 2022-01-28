#include<bits/stdc++.h>
using namespace std;

//O(3N)
// bool isSafe(int r, int c, vector<vector<bool>> &matrix){
//     //Left
//     int row = r;
//     int col = c-1;
//     while(col>=0){
//         if(matrix[row][col]) {
//             return false;
//         }
//         col--;
//     }

//     //Top Left
//     row = r-1;
//     col = c-1;
//     while(col>=0 && row>=0){
//         if(matrix[row][col]) {
//             return false;
//         }
//         col--;
//         row--;
//     }

//     //Bottom Left
//     row = r+1;
//     col = c-1;
//     while(col>=0 && row<matrix[0].size()){
//         if(matrix[row][col]) {
//             return false;
//         }
//         col--;
//         row++;
//     }

//     return true;
// }

//O(3N)
// bool isSafe(int r, int c, vector<vector<bool>> &matrix){
//     for(int i=r, j=c; i>=0 && j>=0; i--,j--){
//         if(matrix[i][j]) return false;
//     }
//     for(int i=r, j=c; i>=0 && j>=0; i,j--){
//         if(matrix[i][j]) return false;
//     }
//     for(int i=r, j=c; i<matrix[0].size() && j>=0; i++,j--){
//         if(matrix[i][j]) return false;
//     }
//     return true;
// }

unordered_map<int, bool> rowHash;
unordered_map<int, bool> bottomLeftHash;
unordered_map<int, bool> topLeftHash;
vector<vector<string>> all;

//O(1)
bool isSafe(int r, int c, vector<vector<bool>> &matrix){
    if(rowHash[r] || bottomLeftHash[r+c] || topLeftHash[r-c]) return false;
    return true;
}

void solve(vector<vector<bool>> &matrix, int col, int n){
    if(col == n){
        vector<string> rows;
        for (auto x : matrix){
            string s="";
            for (auto y : x){
                if(y) s+="Q";
                else s+=".";
            }
            rows.push_back(s);
        }
        all.push_back(rows);
        return;
    }

    for (int row = 0; row < n; row++){
        if(isSafe(row,col,matrix)){
            matrix[row][col] = true;
            rowHash[row] = true;
            bottomLeftHash[row+col] = true;
            topLeftHash[row-col] = true;
            solve(matrix, col+1, n);
            topLeftHash[row-col] = false;
            bottomLeftHash[row+col] = false;
            rowHash[row] = false;
            matrix[row][col] = false;
        }
    }
    
    return;
}

int main(){
    int n=4;
    vector<vector<bool>> matrix(n, vector<bool>(n,false));
    solve(matrix, 0, n);
}