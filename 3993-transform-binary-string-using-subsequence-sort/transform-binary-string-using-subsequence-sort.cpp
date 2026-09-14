class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n0 = 0, n1 = 0;
        int n = s.size();
        for(auto &it : s){
            if(it == '0'){
                n0++;
            }else{
                n1++;
            }
        }
        vector<bool> sol;
        for(auto &it : strs){
            string toMake = "";
            string curr = "";

            int t0 = 0,t1 = 0;
            for(int i = 0;i<n;i++){
                if(it[i]!=s[i]){
                    toMake.push_back(s[i]);
                    curr.push_back(it[i]);
                }
                if(it[i] == '0'){
                    t0++;
                }else if(it[i] == '1'){
                    t1++;
                }
            }

            if(t1 > n1 || t0 > n0){
                sol.push_back(false);
                continue;
            }

            int d1 = n1 - t1;
            int d0 = n0 - t0;


            // 1 moves to left
            // 0 moves to right
            
            int ptr = 0;
            while(ptr < curr.size()){
                if(curr[ptr] == '?'){
                    if(d0 > 0){
                        curr[ptr] = '0';
                        d0--;
                    }else{
                        curr[ptr] = '1';
                    }
                }
                ptr++;
            }

            bool flag = true;

            int curr0 = 0, toMake0 = 0;
            for(int i = 0;i < curr.size(); i++){
                if(curr[i] == '0'){
                    curr0++;
                }
                if(toMake[i] == '0'){
                    toMake0++;
                }

                if(toMake0 > curr0){
                    flag = false;
                    break;
                }
            }

            sol.push_back(flag);
        }
        return sol;
    }
};