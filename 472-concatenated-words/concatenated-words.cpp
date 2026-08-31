class Solution {
public:
    vector<string> ans;
    set<string> st;
    unordered_map<string, bool> dp;

    bool solve(string s) {

        if(dp.find(s) != dp.end())
            return dp[s];

        int m = s.size();

        for(int i = 0; i < m - 1; i++) {

            string prefix = s.substr(0, i + 1);
            string suffix = s.substr(i + 1);

            if(st.find(prefix) != st.end() &&
               st.find(suffix) != st.end()) {
                return dp[s] = true;
            }

            if(st.find(prefix) != st.end()) {

                if(solve(suffix)) {
                    return dp[s] = true;
                }
            }
        }

        return dp[s] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        for(auto it : words) {
            st.insert(it);
        }

        for(auto it : words) {
            st.erase(it);

            if(solve(it)) {
                ans.push_back(it);
            }

            st.insert(it);
        }

        return ans;
    }
};