class Solution {
public:
    long long solve(int ind , vector<int>& piles){
        long long temp = 0;
        for(auto it : piles){
            temp += (it + ind -1)/ind;
        }
        //cout<<temp<<" "<<ind<<" "<<endl;
        return temp;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =  1;
        int high = *max_element(piles.begin() , piles.end());
        int ans=0;
        while(low<=high){
            int mid = (low+high)/2;
            long long time_taken = solve(mid, piles);
            if(time_taken > h){
                low = mid +1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
        
    }
};