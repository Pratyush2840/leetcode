class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin() , asteroids.end());
        long long temp = mass;
        for(auto it : asteroids){
            if(temp >= it){
                temp += it;
            }
            else{
                return false;
            }
        }
        return true;
    }
};