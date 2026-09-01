class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size())
            return false;

        vector<int> ind;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                ind.push_back(i);
            }
        }
        // dono barabar
        if (ind.size() == 0) {
            vector<int> freq(26, 0);

            for (char c : s) {
                freq[c - 'a']++;

                if (freq[c - 'a'] >= 2)
                    return true;
            }

            return false;
        }
        if (ind.size() != 2)
            return false;

        return s[ind[0]] == goal[ind[1]] &&
               s[ind[1]] == goal[ind[0]];
    }
};