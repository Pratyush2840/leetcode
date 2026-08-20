class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void backtrack(int ind,vector<int>& cur , vector<int>& nums){
        if(cur.size() >= 2)ans.push_back(cur);
        if(ind >= nums.size()){
            return;
        }
        set<int>st;
        for(int i =ind ; i< nums.size() ;i++){
            if(st.find(nums[i]) == st.end()){
                if(cur.empty() || nums[i] >= cur.back()){
                    cur.push_back(nums[i]);
                    backtrack(i +1, cur,nums);
                    cur.pop_back();
                }
                
                st.insert(nums[i]);
            }
        }
        return ;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> cur;
        backtrack(0,cur,nums);
        return ans;    
    }
};