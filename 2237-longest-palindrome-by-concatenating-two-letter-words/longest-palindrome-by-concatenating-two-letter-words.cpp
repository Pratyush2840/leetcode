class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int sim = 0;
        int palindrome = 0;
        map<string , int> mp;
        for(auto it : words){
            string temp =it;
            reverse(temp.begin() , temp.end());
            if(mp.find(temp) != mp.end() && mp[temp] > 0){
                palindrome++;
                mp[temp]--;
            }
            else{
                mp[it]++;
            }
        }
        for(auto it : mp){
            auto temp = it.first;
            if(temp[0] == temp[1] && it.second > 0){
                sim++;
            }
        }
        if(sim){
            //cout<<"similar "<<palindrome;
            return palindrome * 4 +2;
        }
        //cout<<"no similar "<<palindrome;
        return palindrome * 4;
    }
};