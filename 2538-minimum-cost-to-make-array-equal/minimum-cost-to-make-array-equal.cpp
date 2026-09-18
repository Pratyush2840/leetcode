class Solution {
public:
    long long check(int mid , vector<int>& nums, vector<int>& cost ){
        long long temp =0;
        for(int i = 0 ;i< nums.size();i++){
            temp += abs(mid - nums[i]) * 1LL * cost[i];
        }
        return temp;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long low = *min_element(nums.begin() , nums.end());
        long long high = *max_element(nums.begin() , nums.end());
        if(low == high)return 0;
        long long ans = LLONG_MAX;
        while(low <= high){
            long long mid = low + ( high -low )/2;
            long long temp = check(mid , nums, cost);
            long long temp2 = check(mid+1 , nums, cost);
            ans = min(ans , min(temp,temp2));
            if(temp2 > temp){
                high = mid-1;
            }
            else{
                low = mid +1;
            }
            
        }
        return ans;
    }
};