class Solution:
    def reverseWords(self, s: str) -> str:
        arr = s.split()
        ans=""
        for i in arr:
            i = i[::-1]
            ans+=i
            ans+=" "
        n = len(ans)
        ans = ans[:n-1]
        return ans