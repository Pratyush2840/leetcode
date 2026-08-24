class Solution {
public:
    int n ;
    vector<vector<int>> ans;

    void solve(int ind , vector<int>& temp , int target , int sum , vector<int>& arr){
        if(ind == n ){
            if(sum == target)
                ans.push_back(temp);
            return;
        }
        if(sum > target){
            return;
        }

        temp.push_back(arr[ind]);
        //liya aur naage nhi bde
        solve(ind , temp, target,sum + arr[ind],arr);


        temp.pop_back();
        //nhi liya
        solve(ind+1 , temp, target,sum,arr);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> temp;
        int sum =0;
        solve(0, temp,target ,sum,candidates);
        return ans;
    }
};