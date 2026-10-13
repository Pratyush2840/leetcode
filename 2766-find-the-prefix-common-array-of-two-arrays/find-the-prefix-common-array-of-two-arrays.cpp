class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>freq1(n+1,0);
        vector<int>freq2(n+1,0);
        vector<int> result;
        int ans=0;
        for(int i = 0 ;i < n;i++){
            freq1[A[i]]++;
            freq2[B[i]]++;
            for(int j = 0 ; j<= n;j++){
                ans+= min(freq1[j] , freq2[j]);
            }
            result.push_back(ans);
            ans=0;
        }
        return result;

    }
};