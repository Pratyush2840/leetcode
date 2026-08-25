class Solution {
public:
    map<string, int> mp;
    vector<string> ans;
    int n;
    void solve(int ind, string temp2, string s) {
        if(ind == n) {
            if(!temp2.empty())
                temp2.pop_back();
            ans.push_back(temp2);
            return;
        }
        string temp = "";
        for(int i = ind; i < n; i++) {
            temp += s[i];
            if(mp.find(temp) != mp.end()) {
                string old = temp2;
                temp2 += temp;
                temp2 += " ";
                solve(i + 1, temp2, s);
                temp2 = old;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto word : wordDict) {
            mp[word]++;
        }
        solve(0, "", s);
        return ans;
    }
};