class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    void solve(int num , int ind ,int n ,vector<int>& temp){
        if(temp.back() != 0){
            ans.push_back(temp);
            return;
        }
        if(num > n){
            return;
        }
        temp[ind] = num;
        solve(num+1 , ind+1 , n, temp);
        temp[ind] = 0;
        solve(num+1 , ind , n, temp);
        return; 
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp(k,0);
        solve(1,0,n,temp);
        return ans;
    }
};