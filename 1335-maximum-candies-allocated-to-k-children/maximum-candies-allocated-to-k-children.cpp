class Solution {
public:
    long long solve(int candy , vector<int> & candies){
        long long temp =0;
        for(auto it : candies){
            temp += (1LL * it)/candy;
        }
        return temp;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int high = 10000000;
        int low = 1;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long student = solve(mid , candies);
            if(student >= k ){
                ans = mid;
                low = mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
        
    }
};