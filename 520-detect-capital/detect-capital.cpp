class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int upper = 0;
        int lower =0;
        for(auto c : word){
            if(c >= 97)lower++;
            else upper++;
        }
        if(upper == n || lower == n)return true;
        if(lower == n -1 && word[0] <97)return true;
        return false;
    }
};