class Solution {
public:
    int minFlips(int a, int b, int c) {
        if( (a | b) == c )return 0;
        int result = ((a|b) ^ c);
        int result2 = (a & b);
        int result3 = (result & result2);
        int temp1 = __builtin_popcount(result);
        int temp2 = __builtin_popcount(result3);
        return temp1 + temp2;
    }
};