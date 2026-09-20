class Solution {
public:
    unordered_map<string , bool> dp;
    bool solve(string s1 , string s2){
        if(s1 == s2){
            return true;
        }
        if(s1.size() != s2.size()){
            return false;
        }
        if(dp.find(s1+'*'+s2) != dp.end()){
            return dp[s1+'*'+s2];
        }
        int n = s1.size();
        for(int i = 1 ; i < s1.size() ; i++){
            bool swapped = solve(s1.substr(i , n-i) , s2.substr(0 , n-i)) && solve(s1.substr(0 , i) , s2.substr(n-i , i));
            if(swapped){
                return dp[s1+'*'+s2] = true;
            }
            bool not_swapped = solve(s1.substr(0 , i) , s2.substr(0,i)) && solve(s1.substr(i , n-i) , s2.substr(i,n-i));
            if(not_swapped){
                return dp[s1+'*'+s2] = true;
            }
        }
        
        return dp[s1+'*'+s2] = false;
    }
    bool isScramble(string s1, string s2) {
        dp.clear();
        return solve(s1,s2);
        
    }
};