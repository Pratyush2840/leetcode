class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt =0;
        for(int i = 0 ; i < strs[0].size() ; i++){
            char temp = strs[0][i];
            //cout<<temp<<" ";
            for(int j = 1 ; j < strs.size() ; j++){
                string it = strs[j];
                //cout<<it[i]<<" ";
                if(temp > it[i]){
                    //cout<<temp<<it[i]<<endl;
                    cnt++;
                    break;
                }
                temp = it[i];
            }
            cout<<endl;
        }
        return cnt;
    }
};