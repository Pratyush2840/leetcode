class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i = 0 ;i < 32 ; i++){
            int tempa = a & ( 1<<i);
            int tempb = b & ( 1<<i);
            int tempc = c & (1<< i);
            cout<<tempa<<" "<<tempb<<" "<<tempc<<endl;
            if((tempa | tempb) == tempc)continue;
            if(tempa != 0 && tempb != 0)cnt += 2;
            else{
                cnt++;
            }
        }
        return cnt;
    }
};