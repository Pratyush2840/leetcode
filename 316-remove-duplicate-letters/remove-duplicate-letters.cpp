class Solution {
public:
    string removeDuplicateLetters(string s) {

        stack<char> st;
        map<char,int> mp;
        string ans = "";
        vector<int> vis(26,0);

        for(auto it : s){
            mp[it]++;
        }
        for(auto it : s){
            mp[it]--;
            if(vis[it - 'a'] == 1){
                continue;
            }
            while(!st.empty() &&
                  st.top() > it &&
                  mp[st.top()] > 0){

                vis[st.top() - 'a'] = 0;
                st.pop();
            }

            st.push(it);
            vis[it - 'a'] = 1;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};