class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin() , potions.end());
        vector<int> ans(spells.size() , 0);
        for(int i = 0 ; i < spells.size() ; i++){
            auto it = spells[i];
            long long temp = (success + it -1)/it;
            int index = lower_bound(potions.begin() , potions.end() , temp) - potions.begin();
            ans[i] = potions.size()-index;
            
        }
        return ans;

    }
};