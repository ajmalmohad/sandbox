#include<iostream>
#include<vector>
#define long long ll
using namespace std;
void solve();
bool findSolution(int target, int n, int i, int sumLeft, int sumRight,  vector<int> &left, vector<int> &right);

main()
{
    int t=1;
    while(t--) solve();
    return 0;
}

void solve(){
    int n;
    cin>>n;
    int sum = (n*(n+1))/2;
    int target = sum/2;
    if(target*2 != sum){ cout<<"NO"<<endl; return; }
    vector<int> left;
    vector<int> right;
    findSolution(target, n, 1, 0, 0, left, right);
}

bool findSolution(int target, int n, int i, int sumLeft,int sumRight, vector<int> &left, vector<int> &right){
    if(i>n+1 || sumLeft>target || sumRight>target) return false;

    if(sumLeft==target && sumRight==target){
        cout<<"YES"<<'\n';
        cout<<left.size()<<'\n';
        for (auto x : left) cout<<x<<" ";
        cout<<'\n';
        cout<<right.size()<<'\n';
        for (auto x : right) cout<<x<<" ";
        cout<<'\n';
        return true;
    }

    left.push_back(i);
    if(findSolution(target, n, i+1, sumLeft+i, sumRight, left, right)) return true;
    left.pop_back();

    right.push_back(i);
    if(findSolution(target, n, i+1, sumLeft, sumRight+i, left, right)) return true;
    right.pop_back();

    return false;
}