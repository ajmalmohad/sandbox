//Keep a count of All Possible Path -> allpaths
//Keep a count of Paths that reaches destination -> reached
//Probability -> reached/allpaths
//Pick a + or pick a - on each call

#include<iostream>
#include<iomanip>
using namespace std;
void solve();
void recur(string path,int pathsum, int i, int n,  int target);
double allpaths = 0;
double reachedpaths = 0;

int main()
{
    int t=1;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}

void solve(){
    string dest;
    int des = 0;
    cin>>dest;

    string mypath;
    int mpath = 0;
    cin>>mypath;

    for (int i = 0; i < dest.size(); i++){
        if(dest[i]=='+') des++;
        else des--;
    }

    recur(mypath, 0, 0, mypath.size(), des);
    double ans = (reachedpaths/allpaths);
    cout<<fixed<<setprecision(12);
    cout<<ans;
}

void recur(string path, int pathsum, int i, int n,  int target){
    if(i>=n){
        if(pathsum == target){
            reachedpaths++;
        }
        allpaths++;
        return;
    }

    if(path[i]=='+'){
        recur(path, pathsum+1, i+1, n, target);
    }else if(path[i]=='-'){
        recur(path, pathsum-1, i+1, n, target);
    }else{
        recur(path, pathsum+1, i+1, n, target);
        recur(path, pathsum-1, i+1, n, target);
    }

}