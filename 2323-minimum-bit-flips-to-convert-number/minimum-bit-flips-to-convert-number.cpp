class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start ^ goal;
        int ans =0;
        while(temp> 0){
            ans += temp & 1;
            temp>>=1;
        }
        return ans;

    }
};