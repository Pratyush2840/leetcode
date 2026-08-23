class Solution {
public:
    bool sumGame(string num) {
        int leftsum =0;
        int rightsum =0;
        int left_symbol=0;
        int right_symbol=0;
        int n =num.size();
        for(int i = 0 ;i < n;i++){
            if(i<(n+1)/2){
                if(num[i] == '?')left_symbol++;
                else{
                    int temp = num[i] - '0';
                    //cout<<num[i]<<" ";
                    leftsum += temp;
                }
            }
            else{
                if(num[i] == '?')right_symbol++;
                else{
                    int temp = num[i] - '0';
                    rightsum += temp;
                }
            }
        }
        int max_diff= leftsum - rightsum;
        //cout<<leftsum<<" "<<rightsum<<endl;
        int symbol_diff = left_symbol - right_symbol;
        //cout<<max_diff<<" "<<symbol_diff<<endl;
        if(symbol_diff == 0)return (!max_diff == 0);

        if(symbol_diff %2 == 0){
            int pair = (symbol_diff)/2;
            pair *= -9;
            cout<<pair<<" " <<max_diff;
            if(max_diff == pair)return false;
        } 
        return true;
    }
};