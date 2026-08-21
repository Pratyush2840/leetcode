class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(str.begin(), str.end());
        long long int ans = stoll(str);
        if(ans > 2147483647) return -1;
        return ans > n ? ans : -1;
    }
};