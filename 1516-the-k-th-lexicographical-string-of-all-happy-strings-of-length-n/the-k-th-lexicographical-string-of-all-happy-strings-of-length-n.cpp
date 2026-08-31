class Solution {
public:
    string ans;
    int cnt =0;
    void solve(int n , int k , string temp){
        if(temp.size() == n){
            cnt++;
            //cout<<temp<<endl;
            if(cnt == k){
                ans = temp;
            }
            return ;
        }
        if(temp.size() > n)return;
        //do something 
        for(int i=0 ; i < 3 ;i++){
            if(temp.size() == 0  || temp.back() != i + 'a'){
                temp += i + 'a';
                //cout<<temp<<' ';
                //explore
                solve(n , k , temp);
                //revert
                temp.pop_back();
            }
            //cout<<endl;
        }
        return;
    }
    string getHappyString(int n, int k) {
        string temp = "";
        solve(n,k,temp);
        return ans;    
    }
};