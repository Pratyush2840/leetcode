class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        map<char,int> mp;
        string ans= "";
        vector<int> vis(26,0);
        for(auto it : s){
            mp[it]++;
        }
        for(auto it : s){
            if(st.empty()){
                st.push(it);
                mp[it]--;
                vis[it - 'a'] = 1;
                continue;
            }
            if(it == st.top()){
                mp[it]--;
                continue;
            }
            if(!st.empty() && it > st.top() && vis[it - 'a'] == 0){
                st.push(it);
                mp[it]--;
                vis[it - 'a'] = 1;
            }
            else if(!st.empty() && it < st.top() && vis[it  - 'a'] == 0){
                //case 1 i can remove the top character
                while( !st.empty() &&  mp[st.top()] >0  && st.top() > it){
                    vis[st.top() - 'a'] = 0;
                    st.pop();
                }
                st.push(it);
                vis[it - 'a'] =1;
                mp[it]--;
            }
            else{
                mp[it]--;
            }
        }
        while(!st.empty()){
            ans+= (st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};