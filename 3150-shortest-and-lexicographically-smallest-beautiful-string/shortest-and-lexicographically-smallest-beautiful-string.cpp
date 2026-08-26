class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l =0;
        int n = s.size();
        string ans = "";
        while(s[l] == '0')l++;
        int cnt = 1;
        if(k ==1 && s[l] == '1')return "1";
        int r = l+1;
        while(r < n ){
            if(s[r] == '1'){
                cnt++;
                //cout<<cnt<<" ";
                if(cnt >k){
                    l++;
                    cnt--;
                    while(s[l] == '0'){
                        l++;
                    }
                    // cout<<l<<" ";
                }
                if(cnt == k){
                    string sub = s.substr(l , r-l+1);
                    cout<<sub<<endl;
                    if(ans.size() == 0 || sub.size() < ans.size()) ans = sub;
                    else if(sub.size() == ans.size()) ans = min(ans,sub);
                }
                r++;
            }
            else{
                r++;
            }
        }
        return ans;

    }
};