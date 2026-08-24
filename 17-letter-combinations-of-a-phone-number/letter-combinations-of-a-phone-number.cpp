class Solution {
public:
    int n;
    vector<string> ans;
    map<int , string> mp;
    void solve(int ind ,string & temp ,string & digits){
        if(ind == n){
            ans.push_back(temp);
            //cout<<temp<<" ";
            return;
        }
        for(auto ch : mp[digits[ind] - '0']){
            cout<<ch<<endl;
            temp += ch;
            solve(ind +1 , temp , digits);
            temp.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        n  = digits.size();
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string temp ="";
        solve(0,temp,digits);
        return ans;
    }
};