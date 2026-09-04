class Solution {
public:
    int MOD = 1e9 +7;
    typedef long long ll;
    int countHomogenous(string s) {
        string temp = "";
        int ans = 0;
        for(auto it : s){
            if(temp == ""){
                temp += it;
            }
            else if(it == temp.back()){
                temp += it;
            }
            else{
                ll z = temp.size();
                //cout<<temp<<endl;
                temp = "";
                temp += it;
                ans = (ans + ((z*(z+1)) /2)% MOD ) % MOD;
            }
        }
        if(temp.size() != 0){
            ll z = temp.size();
            //cout<<temp<<endl;
            ans = (ans + ((z*(z+1)) /2)% MOD ) % MOD;
        }
        return ans;
    }
};