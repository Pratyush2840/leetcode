class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> arr(n,0);
        for(int i=0;i<shifts.size() ; i++){
            int l = shifts[i][0];
            int r = shifts[i][1];
            int dir = shifts[i][2];
            if(dir == 1){
                arr[l] += 1;
                if(r<n-1){
                    arr[r+1] += -1;
                }
            }else{
                arr[l] += -1;
                if(r<n-1)arr[r+1] += 1;
            }
        }
        for(int i =1 ;i<n;i++){
            arr[i] += arr[i-1];
        }
        for(int i=0;i<n;i++){
            int letter = s[i] - 'a';
            letter = (letter + arr[i])%26;
            if(letter < 0){
                letter += 26;
            }
            s[i] = letter + 'a';
        }
        return s;
    }
};