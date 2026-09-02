class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1 ,0);
        if(n == 0)return result;
        result[0] = 0;
        for(int i = 1 ;i <= n ; i++){
            //agar odd hai toh uska half wale ke bits plus one hoga
            if(i & 1){
                result[i] = result[i/2] + 1;
            }
            //agar even hai toh uske half wali ke bits barabar hi hoga 
            else{
                result[i] = result[i/2];
            }
        }
        return result;
    }
};