class Solution {
public:
    bool f(int n,int ind,vector<int>& nums,vector<vector<int>>& queries , vector<int> diff_arr){
        for(int i =0;i<=ind;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff_arr[l] -= val;
            if(r<n-1){
                diff_arr[r+1] += val;
            }
        }
        for(int i=1;i<n;i++){
            diff_arr[i] += diff_arr[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i] + diff_arr[i] > 0)return false;
        }
        return true;
        
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff_arr(n, 0);
        bool allZero = true;

        for(int x : nums) {
            if(x != 0) {
                allZero = false;
                break;
            }
        }

        if(allZero)
            return 0;

        int low=0;
        int high = queries.size()-1;
        int ans = 1e9;
        while(low<=high){
            int mid = (low+high)/2;
            if(f(n,mid,nums,queries,diff_arr) == true){
                ans = min(ans,mid+1);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(ans==1e9)return -1;
        return ans;
    }
};