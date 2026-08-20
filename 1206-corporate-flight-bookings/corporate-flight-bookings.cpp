class Solution {
public:
    int MOD = 1e9+7;
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff_arr(n,0);
        for(auto it : bookings){
            int l = it[0] -1;
            int r = it[1] -1;
            int val = it[2];
            diff_arr[l] = (diff_arr[l] + val) %MOD;
            if(r <n-1)
                diff_arr[r+1] -= val;
        }
        for(int i=1;i<n;i++){
            diff_arr[i] += diff_arr[i-1];
        }
        return diff_arr;
    }
};