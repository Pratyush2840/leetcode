class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> hash(26,0);
        for(auto c : sentence){
            hash[c - 'a'] =1;
        }
        for(auto it : hash){
            if(it == 0)return false;
        }
        return true;
    }
};