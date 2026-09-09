class Solution {
public:
    long long countCommas(long long n) {
        long long temp = 1000, res = 0;
        while (temp <= n) {
            res += n - temp + 1;
            temp *= 1000;
        }
        return res;
    }
};