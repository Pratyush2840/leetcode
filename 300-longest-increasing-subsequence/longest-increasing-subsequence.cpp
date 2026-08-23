class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        for(auto i:nums){
            if(lis.empty() || i>lis.back()) lis.push_back(i);
            else{
                auto it=lower_bound(lis.begin(),lis.end(),i);
                *it=i;
            }
        }
        return lis.size();
    }
};