class Solution {
public:
    int n;
    int ans =INT_MAX;
    int sum =0;
    void backtrack(int ind ,int k, vector<int> &temp ,vector<int>&cookies){
        if(ind == n){
            int mx = *max_element(temp.begin() , temp.end());
            ans = min(ans,mx);
            return;
        }
        for(int i=0;i<k;i++){
            temp[i] += cookies[ind];
            backtrack(ind +1 , k , temp , cookies);
            temp[i] -= cookies[ind];
        }
        return;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> temp(k,0);
        backtrack(0,k,temp,cookies);
        return ans;
    }
};