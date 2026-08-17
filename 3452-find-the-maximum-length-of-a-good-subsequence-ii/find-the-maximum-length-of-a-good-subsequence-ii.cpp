int dp[5001][51];
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int a[51]={0};
        int ans=0;
        for(int i=n-1;i>=0;i--){
            auto it=mp.find(nums[i]);
            int p;
            if(it==end(mp))p=i;
            else p=it->second;
            for(int j=k;j>=0;j--){
                dp[i][j]=max(1+(i!=p?dp[p][j]:0),1+(j?a[j-1]:0));
                a[j]=max(a[j],dp[i][j]);
            }
            mp[nums[i]]=i;
            ans=max(ans,dp[i][k]);
        }
       return ans;
    }
};