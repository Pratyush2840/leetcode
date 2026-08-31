class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        int m = t.size();
        int n = s.size();

        while(i < n && j < m){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }

        return i == n;
    }
};