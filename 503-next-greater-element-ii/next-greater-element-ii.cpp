class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>stk;
        int n = nums.size();
        for(int i=2*n-1; i>=0; i--){
            int j = i%n;
            while(!stk.empty() && nums[j] >= stk.top()) stk.pop();
            int temp = nums[j];
            if(i<n) nums[j] = stk.empty()?-1: stk.top();
            stk.push(temp);
        }
        return nums;
    }
};