class Solution {
public:
    vector<vector<string>> ans;
    int n;
    bool ispalindrome(string s ,  int l ,int r){
        while(l<r){
            if(s[l] != s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(int ind , vector<string>& cur, string & s){
        if(ind == n) {
            ans.push_back(cur);
            return;
        }
        for(int i = ind ; i< n ;i++){
            if(ispalindrome(s , ind , i)){
                cur.push_back(s.substr(ind , i - ind +1));
                backtrack(i + 1 , cur, s);
                cur.pop_back();
            }
        }
        return;

    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string>cur;
        backtrack(0, cur, s);
        return ans;
    }
};