class Solution {
public:
    long long solve(long long t ,vector<int>& time){
        long long temp=0;
        for(auto it : time){
            temp += t/(1LL * it);
        }
        return temp;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans=0;
        long long low = 1;
        long long high = *min_element(time.begin() , time.end()) *1LL * totalTrips;
        if(totalTrips == 0)return 0;
        while(low <= high){
            long long mid = low + (high-low)/2;
            long long trip_possible = solve(mid , time);
            if(trip_possible >= totalTrips){
                high = mid-1;
                ans = mid;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
};