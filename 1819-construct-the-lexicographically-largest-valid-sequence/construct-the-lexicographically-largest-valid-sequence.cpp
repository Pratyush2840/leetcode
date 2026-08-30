class Solution {
public:
    
    void solve(int ind ,int n , vector<int>&arr , vector<bool> & used , vector<int>& ans){
        if(ind == 2*n -1){
            if(ans.size() >0)return;
            ans = arr;
            return;
        }
        if (arr[ind] != 0)
            return solve(ind + 1, n, arr, used,ans);
        //karna hai 
        for(int i = n ; i>0; i--){
            if(ans.size() > 0 )return;
            if(used[i] == false){
                if (i == 1) {
                    used[i] = true;
                    arr[ind] = 1;
                    solve(ind + 1, n, arr, used,ans);
                    arr[ind] = 0;
                    used[i] = false;
                }
                else{
                    if((ind + i) < 2*n -1 &&  arr[ind + i] == 0){
                        used[i] = true;
                        arr[ind] = i;
                        arr[ind + i] = i;
                        solve(ind+1 , n , arr,used,ans);
                        used[i] = false;
                        arr[ind] = 0;
                        arr[ind + i ] =0;
                    }
                }
            }
        }
        return;

    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> arr(2*n -1 , 0);
        vector<int> ans;
        vector<bool> used(n+1 ,false);
        solve(0 ,n, arr , used , ans);
        return ans;
    }
};