#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<vector<int>> all;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
         unordered_map<int,int> nots;
        recur(candidates,target,0,candidates.size(),0,ans, nots);
        vector<vector<int>> output;
        copy(all.begin(),all.end(),back_inserter(output));
        return output;
    }
    
    void recur(vector<int>& candidates, int target, int i, int n, int sum, vector<int>& ans, unordered_map<int,int> nots){
        if(sum==target){ all.insert(ans); return; }
        if(i>=n || (sum+candidates[i])>target) return;
        if(nots[candidates[i]]){
            recur(candidates, target, i+1, n, sum, ans, nots);
        }else{
            ans.push_back(candidates[i]);
            sum+= candidates[i];
            recur(candidates, target, i+1, n, sum, ans, nots);
            sum-= candidates[i];
            ans.pop_back();
            nots[candidates[i]]++;
            recur(candidates, target, i+1, n, sum, ans, nots);
        }
    }
};


int main(){
    Solution s = Solution();
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    //Contains Duplicates 
    //Use a set to avoid duplicates and convert to vector
    vector<vector<int>> all = s.combinationSum2(candidates,target);
    for (auto x : all){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<'\n';
    }
}