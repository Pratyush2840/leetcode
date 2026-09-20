class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans;
        vector<int> bloom;
        vector<int> dead;
        for(auto it : flowers){
            bloom.push_back(it[0]);
            dead.push_back(it[1]);
        }
        sort(bloom.begin() , bloom.end());
        sort(dead.begin() , dead.end());
        for(auto it : people){
            int num_bloom = upper_bound(bloom.begin() , bloom.end() , it) - bloom.begin();
            int num_dead = lower_bound(dead.begin() , dead.end() , it) - dead.begin();
            ans.push_back(num_bloom - num_dead);
        }
        return ans;
    }
};