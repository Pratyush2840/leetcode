class Solution {
public:
    int reverseDegree(string s) {
        int ans =0;
        int index =1;
        for(auto it : s){
            int val = it - 'a';
            ans += (26 - val) * index;
            index++;
        }
        return ans;
    }
};