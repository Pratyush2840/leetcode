class Solution {
public:
    double solve(int t, vector<int>& dist){
        double tmep =0;
        int n = dist.size();
        for(int i = 0 ;i < n-1; i++){
            tmep += (1LL * dist[i] + t - 1)/t;
        }
        tmep = tmep + (1.0*dist[n-1])/t;
        return tmep;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int high = INT_MAX;
        long long  ans =-1;
        long long low = 1;
        //if(hour == 0)return -1;
        while(low<= high){
            long long mid = 1LL * low + 1LL *(high-low)/2;
            double time_taken = solve(mid , dist);
            if(time_taken <= hour){
                high = mid-1;
                ans = mid;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
        
    }
};