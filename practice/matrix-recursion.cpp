#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,bool> visited;
string dirs = "RDLUWASM";
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,-1,1};

template <int r,int c>
void solve(int (&arr)[r][c], int x, int y, string ans){
    if(y>=r || x>=c || x<0 || y<0 || visited[{x,y}] || arr[y][x]==0) return;
    if(y==r-1 && x==c-1){ cout<<ans<<endl; return; }
    visited[{x,y}] = true;
    for (int i = 0; i < dirs.size(); i++){
        solve(arr, x+dx[i], y+dy[i], ans+" "+dirs[i]);
    }
    visited[{x,y}] = false;
}   

int main()
{
    int arr[3][3] = {{1,0,1},{1,1,0},{1,1,1}};
    // int arr[2][2] = {0};
    solve(arr,0,0,"");
}


