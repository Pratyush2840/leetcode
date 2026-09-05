class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }
        int pos = 0;
        while (pos < st.size() && st[pos] == '0') {
            pos++;
        }
        string ans = st.substr(pos);
        if(ans.empty())return "0";
        return ans;
    }
};