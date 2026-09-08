class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        map<int, int> mp;
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                int j = st.top();
                st.pop();

                mp[i] = j;
                mp[j] = i;
            }
        }

        string ans = "";

        int i = 0;
        int direction = 1;

        while (i < n) {

            if (s[i] == '(' || s[i] == ')') {
                i = mp[i];
                direction = -direction;
            }
            else {
                ans += s[i];
            }

            i += direction;
        }

        return ans;
    }
};