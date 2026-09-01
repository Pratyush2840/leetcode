class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string str = "";

        for (int i = 0; i <= path.size(); i++) {

            if (i == path.size() || path[i] == '/') {

                if (str == "..") {
                    if (!st.empty())
                        st.pop();
                }
                else if (str != "" && str != ".") {
                    st.push(str);
                }

                str = "";
            }
            else {
                str += path[i];
            }
        }

        string ans = "";
        stack<string> temp;

        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }

        while (!temp.empty()) {
            ans += "/" + temp.top();
            temp.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};