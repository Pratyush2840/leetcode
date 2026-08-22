class Solution {
public:
    int solve(int ind ,int money ,vector<int>& price ,vector<int>& needs , vector<vector<int>>& special ){
        if(ind == special.size()){
            for(int i=0;i<needs.size() ;i++){
                money += needs[i] * price[i];
            }
            return money;
        }
        int notpick  = solve(ind+1 , money , price,needs,special);
        int flag=0;
        for(int i=0 ;i<special[ind].size() -1 ;i++){
            if(special[ind][i] > needs[i]){
                flag=1;
            }
        }
        int pick = 1e9;
        if(!flag){
            for(int i=0 ;i<special[ind].size()-1 ;i++){
                needs[i] -= special[ind][i];
            }
            pick = solve(ind, money + special[ind][special[0].size() -1] , price ,needs , special);
            for(int i=0 ;i<special[0].size()-1 ;i++){
                needs[i] += special[ind][i];
            }
        }
        return min(notpick,pick);

    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        return solve(0,0,price,needs,special);
    }
};