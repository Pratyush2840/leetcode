class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int A = INT_MAX;
        int B = INT_MAX;
        for(int n : nums) {
            if(n <= A) {
                A = n;  
            } else if(n <= B) {
                B = n;  
            } else {
                return true;  
            }
        }
        return false;
    }
};